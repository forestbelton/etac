#ifndef ETAC_GAME_H_
#define ETAC_GAME_H_

#include <lua.h>
#include <stddef.h>
#include <stdint.h>

#include "ui/screen.h"

#define MAX_OBJECTS 100

/*
 * All data pertaining to a single game.
 */
struct game {
    lua_State *env;
};

/*
 * Initialize a new game.
 * @param game The game structure to initialize.
 * @param match_script The match script to use.
 * @return 0 if initialization succeeded, otherwise -1.
 */
int game_new(struct game *game, const char *match_script);

/*
 * Begin a new game.
 * @param game The game to start playing.
 */
void game_start(struct game *game);

/*
 * Draw the game to the screen.
 * @param game The game structure to draw.
 */
void game_draw(struct game *game);

#endif
