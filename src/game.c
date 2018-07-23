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

    if (load_error) {
        fprintf(stderr, "error (lua): %s\n", lua_tostring(game->env, -1));
        lua_pop(game->env, 1);

        return -1;
    }

    const int match_load_error = luaL_loadfile(game->env, match_script)
        || lua_pcall(game->env, 0, 1, 0);

    if (match_load_error) {
        fprintf(stderr, "error (lua): %s\n", lua_tostring(game->env, -1));
        lua_pop(game->env, 1);

        return -1;
    }

    game->screen = malloc(sizeof *game->screen);
    if (game->screen == NULL) {
        fprintf(stderr, "error: could not allocate screen\n");
        lua_close(game->env);

        return -1;
    }

    screen_init(game->screen);
    game_log(game, TB_DEFAULT, TB_DEFAULT, "Welcome to etac v0.0.1");

    return 0;
}

void game_draw(struct game *game) {
    if (!lua_istable(game->env, -1)) {
        fprintf(stderr, "error: game object not on top of lua stack\n");
        exit(EXIT_FAILURE);
    }

    lua_pushvalue(game->env, -1);
    lua_pushstring(game->env, "map");
    lua_gettable(game->env, -2);

    if (!lua_isstring(game->env, -1)) {
        fprintf(stderr, "error: map name is not a string\n");
        exit(EXIT_FAILURE);
    }

    const char *map_name = lua_tostring(game->env, -1);
    const struct tb_cell *map_data = map_by_name(map_name);

    if (map_data == NULL) {
        fprintf(stderr, "error: data for map '%s' not found\n", map_name);
        exit(EXIT_FAILURE);
    }

    screen_draw(game->screen, map_data);
}

void game_log(struct game *game, int fg, int bg, const char *fmt, ...) {
    va_list args;
    int length = 0;
    struct log_node *log_entry = malloc(sizeof *log_entry);

    if (log_entry == NULL) {
        fprintf(stderr, "error: could not allocate log entry\n");
        exit(EXIT_FAILURE);
    }

    va_start(args, fmt);
    length = vsnprintf(log_entry->content, 0, fmt, args);
    va_end(args);

    log_entry->content = malloc(length + 1);
    if (log_entry->content == NULL) {
        fprintf(stderr, "error: could not allocate log entry content\n");
        exit(EXIT_FAILURE);
    }

    va_start(args, fmt);
    vsnprintf(log_entry->content, length + 1, fmt, args);
    va_end(args);

    log_entry->fg = fg;
    log_entry->bg = bg;
    log_entry->next = game->screen->log;

    game->screen->log = log_entry;
}
