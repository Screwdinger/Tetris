#include <iostream>
#include <raylib.h>
#include "game.h"
#include "colors.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(500, 620, "Raylib Tetris");
    SetTargetFPS(60);

    // Loading the font
    Font font = LoadFontEx("Font/JetBrainsMonoNerdFontMono-ExtraLight.ttf", 64, 0, 0);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(game.music);
        game.HandleInput();

        // To delay the quick downward movement of block
        if (EventTriggered(0.5))
        {
            game.MoveBlockDown();
        }

        BeginDrawing();

        ClearBackground(darkBlue);

        // Displaying the "Score" and "Next" and "Game Over" heading
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);

        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);

        if (game.gameOver == true)
        {
            DrawTextEx(font, "Game Over", {320, 450}, 38, 2, WHITE);
        }

        // Drawing the rectangular border for score and next block
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        // To keep the score centre-aligned inside the rectangle
        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);

        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();
}

/*How to display text via Raylib:
1) Load a font
2) Display the text with the loaded font

How to display text:
 void DrawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint);

 1) Font to use
 2) Text to draw
 3) Position to draw the text
 4) Font Size
 5) Spacing of the letters
 6) Colour

To draw rounded recs:
void DrawRectangleRounded(Rectangle rec, float roundness, int segments, Color color);

1) A rect with position and size
2) Roundness
3) Line segments used to approx the roundness
4) Colour struct
*/