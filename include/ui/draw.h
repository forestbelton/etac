#ifndef ETAC_UI_DRAW_H_
#define ETAC_UI_DRAW_H_

#include <stddef.h>

/*
 * Draw a horizontal line segment at the given coordinates. The segment
 * increases along the x-axis.
 * @param x The x-coordinate to start at.
 * @param y The y-coordinate to start at.
 * @param width The length of the line segment.
 */
void draw_horizontal_line(int x, int y, size_t width);

/*
 * Draw a vertical line segment at the given coordinates. The segment increases
 * along the y-axis.
 * @param x The x-coordinate to start at.
 * @param y The y-coordinate to start at.
 * @param width The length of the line segment.
 */
void draw_vertical_line(int x, int y, size_t height);

/*
 * Draw a rectangle at the given coordinates. The rectangle increases along
 * both the axes, starting at (x, y) and ending at (x + width, y + height).
 * @param x The x-coordinate to start at.
 * @param y The y-coordinate to start at.
 * @param width The width of the rectangle.
 * @param height The height of the rectangle.
 */
void draw_rectangle(int x, int y, size_t width, size_t height);

/*
 * Draw a string at the given coordinates. The text is styled with the default
 * styling.
 * @param x The x-coordinate to start at.
 * @param y The y-coordinate to start at.
 * @param str The string to draw.
 */
void draw_string(int x, int y, const char *str);

/*
 * Draw a string at the given coordinates. The text is styled with the given
 * styling.
 * @param x The x-coordinate to start at.
 * @param y The y-coordinate to start at.
 * @param str The string to draw.
 * @param fg The foreground color to use.
 * @param bg The background color to use.
 */
void draw_string_styled(int x, int y, const char *str, int fg, int bg);

#endif
