#ifndef ETAC_VIDEO_H_
#define ETAC_VIDEO_H_

#include <stddef.h>
#include <termbox.h>

#define LOG_LINE_COUNT 3

#define WINDOW_WIDTH  54
#define WINDOW_HEIGHT 14

#define INFO_WIDTH  54
#define INFO_HEIGHT 19

#define OBJECT_COUNT 54 * 14

struct log_node {
    int fg;
    int bg;
    char *content;
    struct log_node *next;
};

struct screen {
    struct tb_cell info[INFO_WIDTH * INFO_HEIGHT];
    struct log_node *log;
};

void screen_init(struct screen *screen);
void screen_draw_window(const struct screen *screen, const struct tb_cell *window);
void screen_draw_object(const struct screen *screen, struct tb_cell object, size_t x, size_t y);

#endif
