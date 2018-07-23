#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termbox.h>

#include "game.h"
#include "video.h"

extern struct tb_cell map_default[];

int main() {
    struct screen screen;
    struct tb_event event;

    struct game game;
    if (game_new(&game, "script/match/siege.lua") == -1) {
        exit(EXIT_FAILURE);
    }

    init_screen(&screen);
    memcpy(&screen.window[0], &map_default[0], sizeof screen.window);

    screen.log[0] = "Test message 1";
    screen.log[1] = "Test message 2";

    tb_init();

    draw_screen(&screen);
    tb_poll_event(&event);

    tb_shutdown();
    return 0;
}
