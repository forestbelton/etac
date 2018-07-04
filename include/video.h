#ifndef ETAC_VIDEO_H_
#define ETAC_VIDEO_H_

#include <termbox.h>

#define LOG_LINE_COUNT 3

#define WINDOW_WIDTH  54
#define WINDOW_HEIGHT 14

#define INFO_WIDTH  54
#define INFO_HEIGHT 19

struct screen {
    struct tb_cell window[WINDOW_WIDTH * WINDOW_HEIGHT];
    struct tb_cell info[INFO_WIDTH * INFO_HEIGHT];
    char *log[LOG_LINE_COUNT];
};

void init_screen(struct screen *screen);
void draw_screen(struct screen *screen);

#endif
