#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
#include <stdio.h>

#include "game.h"

#define PROLOGUE_SCRIPT "script/prologue.lua"

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

    return 0;
}
