//
// Created by szkum on 14.02.2026.
//

#include "render.h"
#include "defs.h"
#include <string.h>
#include "raylib.h"

int dx = 0;
int dy = 0;

void init_window()
{

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Tetris");
    SetTargetFPS(60);

}

void draw_board()
{
    for (int dy = 0; dy < BOARD_HEIGHT; dy++)
    {
        for (dx = 0; dx < BOARD_WIDTH; dx++)
        {
            if (board[dy][dx] == 1)
            {
                DrawRectangle
                (
                    dx * CELL_SIZE,
                    dy * CELL_SIZE,
                    CELL_SIZE,
                    CELL_SIZE,
                    current_piece.color
                );
            }
        }

    }
}

void draw_falling_piece()
{
    for (int dy = 0; dy < 4; dy++)
    {
        for (dx = 0; dx < 4; dx++)
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
}

void draw_example()
{
    BeginDrawing();
    ClearBackground(BLACK);

    draw_board();
    draw_falling_piece();



    EndDrawing();

}