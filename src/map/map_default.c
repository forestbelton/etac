#include <termbox.h>

struct tb_cell map_default[] = {
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_RED },
    { ' ', TB_WHITE, TB_RED },
    { ' ', TB_WHITE, TB_RED },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '|', TB_WHITE, TB_RED },
    { ' ', TB_WHITE, TB_RED },
    { '|', TB_WHITE, TB_RED },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '/', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { '/', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '|', TB_WHITE, TB_RED },
    { ' ', TB_WHITE, TB_RED },
    { '|', TB_WHITE, TB_RED },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_BLUE },
    { '\\', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '/', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_BLUE },
    { '/', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '_', TB_WHITE, TB_BLUE },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { '/', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_BLUE },
    { '/', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_RED },
    { ' ', TB_WHITE, TB_RED },
    { ' ', TB_WHITE, TB_RED },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '\\', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_BLUE },
    { '\\', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '/', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_BLUE },
    { '/', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_BLUE },
    { '\\', TB_WHITE, TB_BLUE },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { '/', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_BLUE },
    { '/', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '\\', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_BLUE },
    { '\\', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '/', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '/', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '\\', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_BLUE },
    { '\\', TB_WHITE, TB_BLUE },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { ' ', TB_DEFAULT, TB_GREEN },
    { '/', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_BLUE },
    { '/', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '\\', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '/', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '\\', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_BLUE },
    { '\\', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '/', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_BLUE },
    { '/', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '\\', TB_WHITE | TB_BOLD, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '\\', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '_', TB_WHITE, TB_BLUE },
    { '/', TB_WHITE, TB_BLUE },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '/', TB_WHITE | TB_BOLD, TB_GREEN },
    { '\\', TB_WHITE | TB_BOLD, TB_GREEN },
    { '\\', TB_WHITE | TB_BOLD, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '\\', TB_WHITE | TB_BOLD, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '\\', TB_WHITE | TB_BOLD, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '|', TB_WHITE | TB_BOLD, TB_YELLOW },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '/', TB_WHITE | TB_BOLD, TB_GREEN },
    { '\\', TB_WHITE | TB_BOLD, TB_GREEN },
    { '\\', TB_WHITE | TB_BOLD, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '\\', TB_WHITE | TB_BOLD, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '/', TB_WHITE | TB_BOLD, TB_GREEN },
    { '\\', TB_WHITE | TB_BOLD, TB_GREEN },
    { '\\', TB_WHITE | TB_BOLD, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '|', TB_WHITE | TB_BOLD, TB_YELLOW },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '/', TB_WHITE | TB_BOLD, TB_GREEN },
    { '\\', TB_WHITE | TB_BOLD, TB_GREEN },
    { '\\', TB_WHITE | TB_BOLD, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '|', TB_WHITE | TB_BOLD, TB_YELLOW },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { '|', TB_WHITE | TB_BOLD, TB_YELLOW },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ',', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN },
    { ' ', TB_WHITE, TB_GREEN }
};
