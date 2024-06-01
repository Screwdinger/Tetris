#include <raylib.h>
#include "grid.h"

int main()
{
    Color darkBlue = {44, 44, 127, 255};

    InitWindow(300, 600, "Raylib Tetris");
    SetTargetFPS(60);

    Grid grid = Grid();
    // grid.display();
    grid.grid[0][0] = 6;
    grid.grid[1][0] = 6;
    grid.grid[2][0] = 6;

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground(darkBlue);
        grid.draw();

        EndDrawing();
    }

    CloseWindow();
}
