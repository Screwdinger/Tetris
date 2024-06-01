#include <raylib.h>
#include "grid.h"

int main()
{
    Color darkBlue = {44, 44, 127, 255};
    
    InitWindow(600, 800, "Raylib Tetris");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.display();

    while(WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground(darkBlue);

        EndDrawing();
    }

    CloseWindow();
}

// 22:57