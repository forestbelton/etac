#ifndef ETAC_MAP_MAP_H_
#define ETAC_MAP_MAP_H_

#include <termbox.h>

/*
 * Retrieve a map by its name.
 * @param name The name of the map.
 * @return The map data, or NULL if no map can be found.
 */
struct tb_cell *map_by_name(const char *name);

extern struct tb_cell map_river_asymmetric[];

#endif
