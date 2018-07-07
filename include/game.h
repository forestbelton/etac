#ifndef ETAC_GAME_H_
#define ETAC_GAME_H_

#include <lua.h>
#include <stddef.h>
#include <stdint.h>

#define MAX_OBJECTS 100

/*
 * An id value that uniquely refers to an object in game space. All valid
 * id values are nonnegative.
 */
typedef int object_id;

/*
 * An object in the game space.
 */
struct object {
    object_id id;
};

/*
 * All data pertaining to a single game.
 */
struct game {
    lua_State *env;
    size_t total_objects;
    object_id next_object_id;
    object_id objects[MAX_OBJECTS];
};

/*
 * Initialize a new game.
 * @param game The game structure to initialize.
 * @return 0 if initialization succeeded, otherwise -1.
 */
int game_new(struct game *game);

/*
 * Add an object to the game.
 * @param game The game to add the new object to.
 * @param script_file The path of the script file that will control this object.
 * @return The newly created object's id value, or -1 if creation failed.
 */
object_id game_add_object(struct game *game, const char *script_file);

/*
 * Remove an object from the game.
 * @param game The game to remove an object from.
 * @param id The id value of the object to remove.
 */
void game_remove_object(struct game *game, object_id id);

#endif
