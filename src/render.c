//
// Created by szkum on 14.02.2026.
//

#include "render.h"
#include "defs.h"
#include <string.h>
#include "raylib.h"

void init_window()
{

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Tetris");
    SetTargetFPS(60);

}

void draw_example()
{
    BeginDrawing();
    ClearBackground(BLACK);

    DrawRectangle
    (
        current_piece.x,
        current_piece.y,
        current_piece.width_in_cells * CELL_SIZE,
        current_piece.height_in_cells * CELL_SIZE,
        WHITE
    );



    EndDrawing();

}