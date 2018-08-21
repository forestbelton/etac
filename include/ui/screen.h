#ifndef ETAC_VIDEO_H_
#define ETAC_VIDEO_H_

#include <stddef.h>
#include <termbox.h>
#include <lua.h>
#include "map/map.h"

#define LOG_LINE_COUNT 3

#define WINDOW_WIDTH  54
#define WINDOW_HEIGHT 14

#define INFO_WIDTH  54
#define INFO_HEIGHT 19

/*
 * Draw the game window.
 */
void screen_draw_window();

/*
 * Draw the game map.
 * @param map The map structure to render in the window.
 */
void screen_draw_map(const struct map *map);

/*
 * Draw a game object in the window space.
 * @param object The cell of the game object.
 * @param x The x coordinate of the cell relative to the window.
 * @param y The y-coordinate of the cell relative to the window.
 */
void screen_draw_object(struct tb_cell object, size_t x, size_t y);

/*
 * Draw the game action log.
 * @param env The Lua environment containing the match object.
 */
void screen_draw_logs(lua_State *env);

#endif
