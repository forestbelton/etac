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
    struct lua_value value;
    int i = lua_gettop(state);

    log_fmt(LOGLEVEL_DEBUG, "=== stack");
    while (i > 0) {
        lua_at(state, i, &value);

        switch (value.ty) {
            case LUA_TSTRING:
                log_fmt(LOGLEVEL_DEBUG, "%d: \'%s\'", i, value.str);
                break;

            case LUA_TBOOLEAN:
                log_fmt(LOGLEVEL_DEBUG, "%d: %s", i, value.boolean ? "true" : "false");
                break;

            case LUA_TNUMBER:
                log_fmt(LOGLEVEL_DEBUG, "%d: %g", i, value.number);
                break;

            default:
                log_fmt(LOGLEVEL_DEBUG, "%d: %s", i, value.tyname);
                break;
        }

        --i;
    }
    log_fmt(LOGLEVEL_DEBUG, "===");
}

void lua_get_field(lua_State *state, int table_index, const char *key, struct lua_value *value) {
    lua_pushstring(state, key);
    lua_gettable(state, table_index - 1);

    lua_at(state, -1, value);
    lua_dump_stack(state);

    lua_pop(state, 1);
}
