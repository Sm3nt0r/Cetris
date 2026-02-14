//
// Created by szkum on 14.02.2026.
//

#ifndef TETRIS_DEFS_H
#define TETRIS_DEFS_H

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define CELL_SIZE 30

#define WINDOW_WIDTH (BOARD_WIDTH * CELL_SIZE)
#define WINDOW_HEIGHT (BOARD_HEIGHT * CELL_SIZE)

typedef struct{
    int x;
    int y;
    int shape[4][4];
    int width_in_cells;
    int height_in_cells;
    bool is_falling;
} Piece;

extern int J_shape[4][4];
extern int L_shape[4][4];
extern int T_shape[4][4];
extern int Z_shape[4][4];
extern int S_shape[4][4];
extern int O_shape[4][4];

extern Piece current_piece;

#endif //TETRIS_DEFS_H