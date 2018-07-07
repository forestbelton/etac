#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
#include <stdio.h>

#include "game.h"

#define MAIN_SCRIPT_FILE "script/main.lua"

int game_new(struct game *game) {
    game->env = luaL_newstate();
    if (game->env == NULL) {
        return -1;
    }

    const int load_error = luaL_loadfile(game->env, MAIN_SCRIPT_FILE)
        || lua_pcall(game->env, 0, 0, 0);

    if (load_error) {
        fprintf(stderr, "error (lua): %s\n", lua_tostring(game->env, -1));
        lua_pop(game->env, 1);

        return -1;
    }

    game->total_objects = 0;
    game->next_object_id = 0;

    return 0;
}

object_id game_add_object(struct game *game, const char *script_file) {
    // no more objects allowed
    if (game->total_objects >= MAX_OBJECTS) {
        return -1;
    }

    const int load_error = luaL_loadfile(game->env, script_file)
        || lua_pcall(game->env, 0, 0, 0);

    // could not load script
    if (load_error) {
        fprintf(stderr, "error (lua): %s\n", lua_tostring(game->env, -1));
        lua_pop(game->env, 1);

        return -1;
    }

    const object_id id = game->next_object_id++;
    // TODO: Instantiate Lua object with this ID.

    return id;
}

void game_remove_object(struct game *game, object_id id) {
    // TODO: Remove Lua object with this ID.
}
