//
// Created by szkum on 14.02.2026.
//

#include "game.h"
#include "raylib.h"
#include "defs.h"
#include "string.h"

int L_shape[4][4] = {
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0}
};

int J_shape[4][4] = {
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0}
};

Piece current_piece;

void build_L(int shape[4][4])
{
    current_piece.x = (WINDOW_WIDTH/2)-CELL_SIZE;
    current_piece.y = (WINDOW_HEIGHT/2)-CELL_SIZE;
    memcpy(current_piece.shape, shape, sizeof(shape));
    current_piece.width_in_cells = 2;
    current_piece.height_in_cells = 2;
    current_piece.is_falling = true;
}

void update_game()
{
    if (!current_piece.x) {
        build_L(L_shape);
    }

    if (current_piece.is_falling)
    {
        current_piece.y++;
    }

    if (current_piece.y >= WINDOW_HEIGHT - current_piece.height_in_cells * CELL_SIZE)
    {
        current_piece.is_falling = false;
    }
}