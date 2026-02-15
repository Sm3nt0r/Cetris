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

bool is_moving = false;
bool is_rotating = false;

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
    current_piece.is_falling = true;
    current_piece.color = WHITE;
    current_piece.is_active = true;
}

void rotate_clockwise(int shape[4][4])
{
    if (!current_piece.is_active) {return;}

    int tmp[4][4];

    for (int dy = 0; dy < 4; dy++)
    {
        for (int dx = 0; dx < 4; dx++)
        {
            tmp[dx][3 - dy] = shape[dy][dx];
        }
    }

    for (int dy = 0; dy < 4; dy++)
    {
        for (int dx = 0; dx < 4; dx++)
        {
            shape[dy][dx] = tmp[dy][dx];
        }
    }

}

void rotate_counterclockwise(int shape[4][4])
{
    if (!current_piece.is_active) {return;}

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

    current_piece.is_falling = false;
    current_piece.is_active = false;

    if (fall_delay >= 0.1f) {
        fall_delay -= 0.05f;
    }

}

CollisionType is_colliding(Piece *piece, int offset_x, int offset_y)
{
    for (int dy = 0; dy < 4; dy++)
    {
        for (int dx = 0; dx < 4; dx++)
        {

            if (piece->shape[dy][dx] != 1) {continue;}

            int board_x = piece->x + dx + offset_x;
            int board_y = piece->y + dy + offset_y;

            if (board_x < 0)
            {
                return COLLISION_LEFT;
            }

            if (board_x > BOARD_WIDTH)
            {
                return COLLISION_RIGHT;
            }

            if (board_y >= BOARD_HEIGHT)
            {
                return COLLISION_BOTTOM;
            }

            if (board[board_y][board_x] != 0)
            {
                return COLLISION_STACK;
            }

        }
    }

    return COLLISION_NONE;
}


void update_game()
{
    if ((IsKeyReleased(KEY_LEFT) || IsKeyReleased(KEY_RIGHT)) && is_moving) {
        is_moving = false;
    }

    if ((IsKeyReleased(KEY_Z) || IsKeyReleased(KEY_X)) && is_rotating)
    {
        is_rotating = false;
    }

    if (!current_piece.is_active) {
        build(T_shape);
    }

    if (!current_piece.is_falling)
    {
        return;
    }

    if (move_timer >= move_delay) {

        if (IsKeyDown(KEY_RIGHT) && !is_moving)
        {
            if (is_colliding(&current_piece, 1, 0) != COLLISION_RIGHT) {
                is_moving = true;
                current_piece.x++;
                fall_timer -= 0.1f; // may need to delete this later but for now its fine
            }
        }

        if (IsKeyDown(KEY_LEFT) && !is_moving) {
            if (is_colliding(&current_piece, -1, 0) != COLLISION_LEFT) {
                is_moving = true;
                current_piece.x--;
                fall_timer -= 0.1f; // may need to delete this later but for now its fine
            }
        }

        if (IsKeyDown(KEY_X))
        {
            if (!is_rotating)
            {
                is_rotating = true;
                rotate_clockwise(current_piece.shape);
            }
        }

        if (IsKeyDown(KEY_Z))
        {
            if (!is_rotating)
            {
                is_rotating = true;
                rotate_counterclockwise(current_piece.shape);
            }
        }

        move_timer = 0.0f;
    }

    if (current_piece.is_falling)
    {
        if (is_colliding(&current_piece, 0, 1) == COLLISION_STACK || is_colliding(&current_piece, 1, 1) == COLLISION_BOTTOM)
        {
            add_piece_to_stack(current_piece);
            return;
        }

        fall_timer += GetFrameTime();
        move_timer += GetFrameTime();

        if (fall_timer >= fall_delay)
        {
            current_piece.y++;
            fall_timer = 0.0f;
        }
    }
}