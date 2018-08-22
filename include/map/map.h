#ifndef ETAC_MAP_MAP_H_
#define ETAC_MAP_MAP_H_

#include <termbox.h>

struct map {
    const struct tb_cell *data;
    const unsigned width;
    const unsigned height;
};

/*
 * Retrieve a map by its name.
 * @param name The name of the map.
 * @return The map struct, or NULL if no map can be found.
 */
struct map *map_by_name(const char *name);

extern struct map map_river_asymmetric;

#endif
