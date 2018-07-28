#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termbox.h>

#include "game.h"
#include "map/map.h"
#include "ui/screen.h"
#include "util.h"

#define PROLOGUE_SCRIPT "script/prologue.lua"

extern struct tb_cell map_default[];

int game_new(struct game *game, const char *match_script) {
    game->env = luaL_newstate();
    if (game->env == NULL) {
        return -1;
    }

    luaL_openlibs(game->env);

    const int load_error = luaL_loadfile(game->env, PROLOGUE_SCRIPT)
        || lua_pcall(game->env, 0, 0, 0);
    verify(!load_error, "[lua]: %s", lua_tostring(game->env, -1));

    const int match_load_error = luaL_loadfile(game->env, match_script)
        || lua_pcall(game->env, 0, 1, 0);
    verify(!match_load_error, "[lua]: %s", lua_tostring(game->env, -1));

    game->screen = malloc(sizeof *game->screen);
    verify0(game->screen != NULL, "could not allocate screen");
    screen_init(game->screen);

    return 0;
}

void game_dump_stack(struct game *game) {
    int i;
    int top = lua_gettop(game->env);

    for (i = 1; i <= top; ++i) {
        int t = lua_type(game->env, i);

        switch (t) {
            case LUA_TSTRING:
                printf("`%s`", lua_tostring(game->env, i));
                break;

            case LUA_TBOOLEAN:
                printf(lua_toboolean(game->env, i) ? "true" : "false");
                break;

            case LUA_TNUMBER:  /* numbers */
                printf("%g", lua_tonumber(game->env, i));
                break;

            default:  /* other values */
                printf("%s", lua_typename(game->env, t));
                break;
        }

        putchar(' ');
    }

    putchar('\n');
}

void game_draw(struct game *game) {
    tb_clear();

    verify0(lua_istable(game->env, -1), "game object not on top of stack");

    // Draw the game map
    lua_pushstring(game->env, "map");
    lua_gettable(game->env, -2);
    verify0(lua_isstring(game->env, -1), "map name not a string");

    const char *map_name = lua_tostring(game->env, -1);
    const struct tb_cell *map_data = map_by_name(map_name);

    verify(map_data != NULL, "data for map '%s' not found", map_name);
    screen_draw_window(game->screen, map_data);
    lua_pop(game->env, 1);

    screen_draw_logs(game->env);

    // Draw the game entities
    lua_pushstring(game->env, "entities");
    lua_gettable(game->env, -2);
    verify0(lua_istable(game->env, -1), "entity list is not a table");

    lua_pushnil(game->env);
    while (lua_next(game->env, -2) != 0) {
        lua_pushvalue(game->env, -2);

        lua_pushstring(game->env, "x");
        lua_gettable(game->env, -3);
        verify0(lua_isnumber(game->env, -1), "entity.x is not a number");

        const size_t x = (size_t)lua_tonumber(game->env, -1);
        lua_pop(game->env, 1);

        lua_pushstring(game->env, "y");
        lua_gettable(game->env, -3);
        verify0(lua_isnumber(game->env, -1), "entity.y is not a number");

        const size_t y = (size_t)lua_tonumber(game->env, -1);
        lua_pop(game->env, 1);

        lua_pushstring(game->env, "sprite");
        lua_gettable(game->env, -3);
        verify0(lua_isstring(game->env, -1), "entity.sprite is not a string");

        const char *sprite = lua_tostring(game->env, -1);
        struct tb_cell object = { *sprite, TB_DEFAULT, TB_DEFAULT };
        object.bg = map_data[WINDOW_WIDTH * y + x].bg;

        lua_pop(game->env, 3);
        screen_draw_object(object, x, y);
    }

    tb_present();
}
