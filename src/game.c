#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termbox.h>

#include "game.h"
#include "ui/screen.h"

#define PROLOGUE_SCRIPT "script/prologue.lua"

extern struct tb_cell map_default[];

int game_new(struct game *game, const char *match_script) {
    game->env = luaL_newstate();
    if (game->env == NULL) {
        return -1;
    }

    luaL_openlibs(game->env);

    const int load_error = luaL_loadfile(game->env, PROLOGUE_SCRIPT)
        || lua_pcall(game->env, 0, 0, 0);

    if (load_error) {
        fprintf(stderr, "error (lua): %s\n", lua_tostring(game->env, -1));
        lua_pop(game->env, 1);

        return -1;
    }

    const int match_load_error = luaL_loadfile(game->env, match_script)
        || lua_pcall(game->env, 0, 1, 0);

    if (match_load_error) {
        fprintf(stderr, "error (lua): %s\n", lua_tostring(game->env, -1));
        lua_pop(game->env, 1);

        return -1;
    }

    game->screen = malloc(sizeof *game->screen);
    if (game->screen == NULL) {
        fprintf(stderr, "error: could not allocate screen");
        lua_close(game->env);

        return -1;
    }

    screen_init(game->screen);

    // TODO: Remove
    memcpy(&game->screen->window[0], &map_default[0], sizeof game->screen->window);
    game_log(game, TB_DEFAULT, TB_DEFAULT, "Welcome to etac v0.0.1");
    game_log(game, TB_RED, TB_DEFAULT, "You have died!");

    return 0;
}

void game_draw(struct game *game) {
    screen_draw(game->screen);
}

void game_log(struct game *game, int fg, int bg, const char *fmt, ...) {
    va_list args;
    int length = 0;
    struct log_node *log_entry = malloc(sizeof *log_entry);

    if (log_entry == NULL) {
        fprintf(stderr, "error: could not allocate log entry");
        exit(EXIT_FAILURE);
    }

    va_start(args, fmt);
    length = vsnprintf(log_entry->content, 0, fmt, args);
    va_end(args);

    log_entry->content = malloc(length + 1);
    if (log_entry->content == NULL) {
        fprintf(stderr, "error: could not allocate log entry content");
        exit(EXIT_FAILURE);
    }

    va_start(args, fmt);
    vsnprintf(log_entry->content, length + 1, fmt, args);
    va_end(args);

    log_entry->fg = fg;
    log_entry->bg = bg;
    log_entry->next = game->screen->log;

    game->screen->log = log_entry;
}
