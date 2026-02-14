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

    int dx = 0;

    for (int dy = 0; dy < current_piece.height_in_cells; dy++)
    {
        for (dx = 0; dx < current_piece.width_in_cells; dx++)
        {
            if (current_piece.shape[dy][dx] == 1)
            {
                DrawRectangle
                (
                    (current_piece.x + dx) * CELL_SIZE,
                    (current_piece.y + dy) * CELL_SIZE,
                    CELL_SIZE,
                    CELL_SIZE,
                    current_piece.color
                );
            }
        }

    }



    EndDrawing();

}