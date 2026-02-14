//
// Created by szkum on 14.02.2026.
//

#include "raylib.h"
#include "game.h"
#include "defs.h"
#include "render.h"

int main(void)
{

    init_window();

    while (!WindowShouldClose())
    {
        update_game();

        draw_example();
    }

    CloseWindow();

    return 0;
}
