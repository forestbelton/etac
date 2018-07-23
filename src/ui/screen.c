#include "ui/draw.h"
#include "ui/screen.h"

#define ARRAYLEN(arr) ((sizeof (arr)) / (sizeof (arr)[0]))

const struct tb_cell EMPTY_CELL = {
    ' ',
    TB_DEFAULT,
    TB_DEFAULT
};

void screen_init(struct screen *screen) {
    size_t i;

    for (i = 0; i < ARRAYLEN(screen->info); ++i) {
        screen->info[i] = EMPTY_CELL;
    }

    screen->log = NULL;
    screen->total_objects = 0;
}

void screen_draw(const struct screen *screen, const struct tb_cell *window) {
    size_t i;

    tb_clear();

    // window box
    draw_rectangle(1, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    tb_blit(2, 1, WINDOW_WIDTH, WINDOW_HEIGHT, &window[0]);

    // info box
    draw_vertical_line(WINDOW_WIDTH + 4, 0, WINDOW_HEIGHT + 2);
    tb_blit(WINDOW_WIDTH + 6, 0, INFO_WIDTH, INFO_HEIGHT, &screen->info[0]);

    // chat box
    draw_horizontal_line(0, WINDOW_HEIGHT + 2, tb_width());

    struct log_node *node = screen->log;
    for (i = 0; node != NULL && i < LOG_LINE_COUNT; ++i) {
        draw_string_styled(0, WINDOW_HEIGHT + 3 + (LOG_LINE_COUNT - i), node->content, node->fg, node->bg);
        node = node->next;
    }

    tb_present();
}
