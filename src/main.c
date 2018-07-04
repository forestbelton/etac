#include <stdio.h>
#include <termbox.h>
#include "video.h"

int main() {
    struct screen screen;
    struct tb_event event;

    init_screen(&screen);

    tb_init();
    tb_select_output_mode(TB_OUTPUT_256);

    draw_screen(&screen);
    tb_poll_event(&event);

    tb_shutdown();
    return 0;
}
