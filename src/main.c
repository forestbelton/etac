#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termbox.h>

#include "game.h"
#include "log.h"

int main() {
    log_init(LOGLEVEL_DEBUG);

    struct game game;
    if (game_new(&game, "script/match/siege.lua") == -1) {
        log_close();
        exit(EXIT_FAILURE);
    }

    tb_init();

    game_draw(&game);
    tb_poll_event(&event);

    tb_shutdown();
    return 0;
}
