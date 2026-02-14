//
// Created by szkum on 14.02.2026.
//

#include "render.h"

void init_window()
{

    InitWindow(800, 600, "Tetris");
    SetTargetFPS(60);

}

void draw_example()
{

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Hej misio :3", 350, 280, 20, WHITE);
        EndDrawing();
    }

    CloseWindow();

}