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

int T_shape[4][4] = {
    {0, 1, 0, 0},
    {1, 1, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

Piece current_piece;

int board[20][10];

float fall_timer = 0.0f;
float fall_delay = 0.5f;

// moving every by one cell every frame sends the tetrimino into another fucking dimension so yeah
// wait the fuck up
// 0.1 sec seems fine but I might change it if its weird
float move_timer = 0.0f;
float move_delay = 0.1f;

void build(int shape[4][4])
{
    current_piece.x = (BOARD_WIDTH/2)-1;
    current_piece.y = 1;
    memcpy(current_piece.shape, shape, sizeof(int) * 4 * 4);
    current_piece.width_in_cells = 3;
    current_piece.height_in_cells = 2;
    current_piece.is_falling = true;
    current_piece.color = WHITE;
    current_piece.is_active = true;
}

void add_piece_to_stack(Piece piece)
{

    for (int dy = 0; dy < 4; dy++)
    {
     for (int dx = 0; dx < 4; dx++)
     {
        if (piece.shape[dy][dx] == 1)
        {
            board[piece.y + dy][piece.x + dx] = 1;
        }
     }
    }

}

void update_game()
{
    if (!current_piece.is_active) {
        build(T_shape);
    }

    if (move_timer >= move_delay) {

        if (IsKeyDown(KEY_RIGHT)) {
            current_piece.x++;
            fall_timer -= 0.1f; // may need to delete this later but for now its fine
        }

        if (IsKeyDown(KEY_LEFT)) {
            current_piece.x--;
            fall_timer -= 0.1f; // may need to delete this later but for now its fine
        }

        move_timer = 0.0f;
    }

    if (current_piece.is_falling)
    {
        fall_timer += GetFrameTime();
        move_timer += GetFrameTime();

        if (fall_timer >= fall_delay)
        {
            current_piece.y++;
            fall_timer = 0.0f;
        }
    }

    if (current_piece.y*30 >= WINDOW_HEIGHT - current_piece.height_in_cells * CELL_SIZE)
    {
        current_piece.is_falling = false;
        current_piece.is_active = false;

        add_piece_to_stack(current_piece);

        if (fall_delay >= 0.1f) {
            fall_delay -= 0.05f;
        }
    }
}