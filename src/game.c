#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
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
        fprintf(stderr, "error: could not allocate screen");
        lua_close(game->env);

        return -1;
    }

    screen_init(game->screen);
    memcpy(&game->screen->window[0], &map_default[0], sizeof game->screen->window);
    game->screen->log[0] = "Test message 1";
    game->screen->log[1] = "Test message 2";

    return 0;
}

void game_draw(struct game *game) {
    screen_draw(game->screen);
}
