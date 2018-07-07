#include <termbox.h>
#include "ui/draw.h"

void draw_horizontal_line(int x, int y, size_t width) {
    size_t i;

    for (i = 0; i < width; ++i) {
        tb_change_cell(x + i, y, '-', TB_DEFAULT, TB_DEFAULT);
    }
}

void draw_vertical_line(int x, int y, size_t height) {
    size_t i;

    for (i = 0; i < height; ++i) {
        tb_change_cell(x, y + i, '|', TB_DEFAULT, TB_DEFAULT);
    }
}

void draw_rectangle(int x, int y, size_t width, size_t height) {
    tb_change_cell(x, y, L'┌', TB_DEFAULT, TB_DEFAULT);
    draw_horizontal_line(x + 1, y, width);

    tb_change_cell(x + width + 1, y, L'┐', TB_DEFAULT, TB_DEFAULT);
    draw_vertical_line(x + width + 1, y + 1, height);

    tb_change_cell(x + width + 1, y + height + 1, L'┘', TB_DEFAULT, TB_DEFAULT);
    draw_horizontal_line(x + 1, y + height + 1, width);

    tb_change_cell(x, y + height + 1, L'└', TB_DEFAULT, TB_DEFAULT);
    draw_vertical_line(x, y + 1, height);
}

void draw_string(int x, int y, const char *s) {
    size_t i;

    for (i = 0; s[i] != 0; ++i) {
        tb_change_cell(x + i, y, s[i], TB_DEFAULT, TB_DEFAULT);
    }
}

void draw_string_styled(int x, int y, const char *s, int fg, int bg) {
    size_t i;

    for (i = 0; s[i] != 0; ++i) {
        tb_change_cell(x + i, y, s[i], fg, bg);
    }
}
