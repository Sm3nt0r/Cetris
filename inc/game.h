//
// Created by szkum on 14.02.2026.
//

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include "raylib.h"
#include "defs.h"

void update_game();

void build(int shape[4][4]);

void add_piece_to_stack(Piece piece);

#endif //TETRIS_GAME_H