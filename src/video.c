#include <stdio.h>
#include "video.h"

#define ARRAYLEN(arr) ((sizeof (arr)) / (sizeof (arr)[0]))

const struct tb_cell EMPTY_CELL = {
    ' ',
    TB_DEFAULT,
    TB_DEFAULT
};

void init_screen(struct screen *screen) {
    size_t i;

    for (i = 0; i < ARRAYLEN(screen->window); ++i) {
        screen->window[i] = EMPTY_CELL;
    }

    for (i = 0; i < ARRAYLEN(screen->info); ++i) {
        screen->info[i] = EMPTY_CELL;
    }

    for (i = 0; i < ARRAYLEN(screen->log); ++i) {
        screen->log[i] = "";
    }
}

void draw_vertical_line(int x, int y, int height) {
    int i;

    for (i = 0; i < height; ++i) {
        tb_change_cell(x, y + i, '|', TB_DEFAULT, TB_DEFAULT);
    }
}

void draw_horizontal_line(int x, int y, int width) {
    int i;

    for (i = 0; i < width; ++i) {
        tb_change_cell(x + i, y, '-', TB_DEFAULT, TB_DEFAULT);
    }
}

void draw_rectangle(int x, int y, int width, int height) {
    tb_change_cell(x, y, L'┌', TB_DEFAULT, TB_DEFAULT);
    draw_horizontal_line(x + 1, y, width);

    tb_change_cell(x + width + 1, y, L'┐', TB_DEFAULT, TB_DEFAULT);
    draw_vertical_line(x + width + 1, y + 1, height);

    tb_change_cell(x + width + 1, y + height + 1, L'┘', TB_DEFAULT, TB_DEFAULT);
    draw_horizontal_line(x + 1, y + height + 1, width);

    tb_change_cell(x, y + height + 1, L'└', TB_DEFAULT, TB_DEFAULT);
    draw_vertical_line(x, y + 1, height);
}

void draw_text(int x, int y, const char *s) {
    size_t i;

    for (i = 0; s[i] != 0; ++i) {
        tb_change_cell(x + i, y, s[i], TB_DEFAULT, TB_DEFAULT);
    }
}

void draw_screen(struct screen *screen) {
    int i, x, y;

    tb_clear();

    // window box
    draw_rectangle(1, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    tb_blit(2, 1, WINDOW_WIDTH, WINDOW_HEIGHT, &screen->window[0]);

    // info box
    draw_vertical_line(WINDOW_WIDTH + 4, 0, WINDOW_HEIGHT + 2);
    tb_blit(WINDOW_WIDTH + 6, 0, INFO_WIDTH, INFO_HEIGHT, &screen->info[0]);

    // chat box
    draw_horizontal_line(0, WINDOW_HEIGHT + 2, tb_width());
    for (i = 0; i < ARRAYLEN(screen->log); ++i) {
        draw_text(0, WINDOW_HEIGHT + 3 + i, screen->log[i]);
    }

    tb_present();
}
