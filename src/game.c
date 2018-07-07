#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>

#include "game.h"

void game_new(struct game *game) {
    game->env = luaL_newstate();
    game->total_objects = 0;
    game->next_object_id = 0;
}

object_id game_add_object(struct game *game, const char *script_file) {
    return -1;
}

void game_remove_object(struct game *game, object_id id) {
}
