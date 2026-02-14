//
// Created by szkum on 14.02.2026.
//

#include "game.h"
#include "raylib.h"
#include "defs.h"
#include "string.h"

int L_shape[4][4] = {
    {1, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 0}
};

int J_shape[4][4] = {
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 0}
};

Piece current_piece;

void build(int shape[4][4])
{
    current_piece.x = (BOARD_WIDTH/2)-1;
    current_piece.y = 1;
    memcpy(current_piece.shape, shape, sizeof(int) * 4 * 4);
    current_piece.width_in_cells = 2;
    current_piece.height_in_cells = 3;
    current_piece.is_falling = true;
    current_piece.color = WHITE;
}

float fall_timer = 0.0f;
float fall_delay = 0.5f;

void update_game()
{
    if (!current_piece.x) {
        build(J_shape);
    }

    if (current_piece.is_falling)
    {
        fall_timer += GetFrameTime();

        if (fall_timer >= fall_delay)
        {
            current_piece.y++;
            fall_timer = 0.0f;
        }
    }

    if (current_piece.y*30 >= WINDOW_HEIGHT - current_piece.height_in_cells * CELL_SIZE)
    {
        current_piece.is_falling = false;
    }
}