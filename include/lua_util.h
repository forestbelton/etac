#ifndef ETAC_LUA_UTIL_H_
#define ETAC_LUA_UTIL_H_

#include <lua.h>

struct lua_value {
    int ty;
    union {
        const char *str;
        int boolean;
        double number;
        const char *tyname;
    };
};

/*
 * Read a value.
 * @param state The Lua state to read from.
 * @param index The stack index of the value to read.
 * @param value Where the value will be stored.
 */
void lua_at(lua_State *state, int index, struct lua_value *value);

/*
 * Read a value from a table. An error will occur if there is a type mismatch.
 * @param state The Lua state to read from.
 * @param table_index The stack index of the table to access.
 * @param key The key used to index the table with.
 * @param ty The expected type for the value.
 * @param value Where the value will be stored.
 */
void lua_get_field(
    lua_State *state,
    int table_index,
    const char *key,
    int ty,
    struct lua_value *value
);

/*
 * Display a human-readable version of the Lua runtime.
 * @param state The Lua state to dump.
 */
void lua_dump_stack(lua_State *state);

#endif
