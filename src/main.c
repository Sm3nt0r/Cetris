//
// Created by szkum on 14.02.2026.
//

#include "raylib.h"
#include "game.h"
#include "render.h"


#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define CELL_SIZE 30

int main(void)
{

    init_window();

    draw_example();

    CloseWindow();
    return 0;
}
