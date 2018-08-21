#include "ui/draw.h"
#include "ui/screen.h"
#include "util.h"

void screen_draw_object(struct tb_cell object, size_t x, size_t y) {
    tb_put_cell(x + 2, y + 1, &object);
}

void screen_draw_window(const struct map *map) {
    // window box
    draw_rectangle(1, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    tb_blit(2, 1, WINDOW_WIDTH, WINDOW_HEIGHT, map->data);

    // info box
    draw_vertical_line(WINDOW_WIDTH + 4, 0, WINDOW_HEIGHT + 2);

    // chat box
    draw_horizontal_line(0, WINDOW_HEIGHT + 2, tb_width());
}

void screen_draw_logs(lua_State *env) {
    verify0(lua_istable(env, -1), "game object not on top of stack");

    lua_pushstring(env, "log_entries");
    lua_gettable(env, -2);
    verify0(lua_istable(env, -1), "log_entries is not a table");

    lua_pushnil(env);
    for (size_t i = 0; i < LOG_LINE_COUNT && lua_next(env, -2) != 0; i++) {
        verify0(lua_isstring(env, -1), "log entry is not a string");
        draw_string(0, WINDOW_HEIGHT + 3 + (LOG_LINE_COUNT - i), lua_tostring(env, -1));
        lua_pop(env, 1);
    }

    lua_pop(env, 1);
}
