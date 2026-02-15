//
// Created by szkum on 14.02.2026.
//

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include "raylib.h"
#include "defs.h"

typedef enum
{
    COLLISION_NONE,
    COLLISION_LEFT,
    COLLISION_RIGHT,
    COLLISION_BOTTOM,
    COLLISION_STACK
} CollisionType;

void update_game();

void build(int shape[4][4]);

void add_piece_to_stack(Piece piece);

int is_colliding_with_stack();

void rotate_clockwise(int shape[4][4]);
void rotate_counterclockwise(int shape[4][4]);

#endif //TETRIS_GAME_H