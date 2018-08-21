#include <string.h>
#include "map/map.h"

struct map_entry {
    const char *name;
    struct map *map;
};

struct map_entry map_entries[] = {
    { "river_asymmetric", &map_river_asymmetric }
};

struct map *map_by_name(const char *name) {
    size_t i = 0;

    while (i < sizeof map_entries / sizeof map_entries[0]) {
        const char *entry_name = map_entries[i].name;
        const size_t name_len = strlen(entry_name);

        if (strncmp(entry_name, name, name_len) == 0) {
            return map_entries[i].map;
        }

        ++i;
    }

    return NULL;
}
