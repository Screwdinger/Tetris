#include <raylib.h>
#include "game.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    Color darkBlue = {44, 44, 127, 255};

    InitWindow(300, 600, "Raylib Tetris");
    SetTargetFPS(60);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        game.HandleInput();

        // To delay the quick downward movement of block
        if(EventTriggered(0.05))
        {
            game.MoveBlockDown();
        }

        BeginDrawing();

        ClearBackground(darkBlue);
        game.Draw();
        
        EndDrawing();
    }

    CloseWindow();
}

//1:08:12