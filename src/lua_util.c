#include <lua.h>

#include "log.h"
#include "lua_util.h"
#include "util.h"

void lua_at(lua_State *state, int index, struct lua_value *value) {
    const int ty = lua_type(state, index);
    value->ty = ty;

    switch (ty) {
        case LUA_TSTRING:
            value->str = lua_tostring(state, index);
            break;

        case LUA_TBOOLEAN:
            value->boolean = lua_toboolean(state, index);
            break;

        case LUA_TNUMBER:
            value->number = lua_tonumber(state, index);
            break;

        default:
            value->tyname = lua_typename(state, ty);
            break;
    }
}

void lua_dump_stack(lua_State *state) {
    log_fmt(LOGLEVEL_DEBUG, "=== stack");

    for (int i = lua_gettop(state); i > 0; i--) {
        lua_getglobal(state, "inspect");
        lua_pushvalue(state, i);
        int result = lua_pcall(state, 1, 1, 0);
        verify(result == 0, "couldn't call inspect: %s", lua_tostring(state, -1));
        log_fmt(LOGLEVEL_DEBUG, "%d: %s", i, lua_tostring(state, -1));
        lua_pop(state, 1);
    }

    log_fmt(LOGLEVEL_DEBUG, "===");
}

void lua_get_field(lua_State *state, int table_index, const char *key, int ty, struct lua_value *value) {
    verify(
        lua_istable(state, table_index),
        "expected table but found '%s' while accessing field",
        lua_typename(state, table_index)
    );

    lua_pushstring(state, key);
    lua_gettable(state, table_index - 1);

    lua_at(state, -1, value);
    lua_pop(state, 1);

    verify(
        value->ty == ty,
        "type mismatch for field '%s': found %s, expected %s",
        key,
        lua_typename(state, value->ty),
        lua_typename(state, ty)
    );
}
