#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termbox.h>

#include "game.h"
#include "lua_util.h"
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

    return 0;
}

int game_isover(struct game *game) {
    verify0(lua_istable(game->env, -1), "game object not on top of stack");

    lua_pushstring(game->env, "is_over");
    lua_gettable(game->env, -2);
    lua_pushvalue(game->env, -2);
    verify(lua_pcall(game->env, 1, 0, 0) == 0, "error checking game over status: %s", lua_tostring(game->env, -1));

    const int is_over = lua_toboolean(game->env, -1);
    lua_pop(game->env, 1);

    return is_over;
}

void game_start(struct game *game) {
    game_draw(game);

    log_fmt(LOGLEVEL_DEBUG, "game started");
    while (!game_isover(game)) {
        log_fmt(LOGLEVEL_DEBUG, "taking turn");
        verify0(lua_istable(game->env, -1), "game object not on top of stack");

        lua_pushstring(game->env, "take_turn");
        lua_gettable(game->env, -2);
        lua_pushvalue(game->env, -2);

        verify0(lua_pcall(game->env, 1, 0, 0) == 0, "error taking game turn");
        game_draw(game);
    }

    game_draw(game);
    log_fmt(LOGLEVEL_DEBUG, "game ended");
}

void game_draw(struct game *game) {
    tb_clear();
    screen_draw_window();

    verify0(lua_istable(game->env, -1), "game object not on top of stack");

    // Draw the game map
    struct lua_value map_name;
    lua_get_field(game->env, -1, "map", &map_name);
    verify0(map_name.ty == LUA_TSTRING, "map name is not a string");

    const struct map *map = map_by_name(map_name.str);
    verify(map != NULL, "data for map '%s' not found", map_name);
    screen_draw_map(map);

    // Draw the game logs
    screen_draw_logs(game->env);

    // Draw the game entities
    lua_pushstring(game->env, "entities");
    lua_gettable(game->env, -2);
    verify0(lua_istable(game->env, -1), "entity list is not a table");

    lua_pushnil(game->env);
    while (lua_next(game->env, -2) != 0) {
        struct lua_value entity_x;
        lua_get_field(game->env, -1, "x", &entity_x);
        verify0(entity_x.ty == LUA_TNUMBER, "entity.x is not a number");
        const size_t x = (size_t)entity_x.number;

        struct lua_value entity_y;
        lua_get_field(game->env, -1, "y", &entity_y);
        verify0(entity_y.ty == LUA_TNUMBER, "entity.y is not a number");
        const size_t y = (size_t)entity_y.number;

        struct lua_value entity_sprite;
        lua_get_field(game->env, -1, "sprite", &entity_sprite);
        verify0(entity_sprite.ty == LUA_TSTRING, "entity.sprite is not a string");
        const char *sprite = entity_sprite.str;

        log_fmt(LOGLEVEL_TRACE, "drawing entity (sprite %s) at %zu, %zu", sprite, x, y);
        struct tb_cell object = { *sprite, TB_BLACK, TB_DEFAULT };
        object.bg = map->data[map->width * y + x].bg;
        screen_draw_object(object, x, y);

        lua_pop(game->env, 1);
    }

    lua_pop(game->env, 1);
    tb_present();
}
