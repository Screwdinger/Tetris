#include "grid.h"
#include <iostream>

Grid::Grid()
{
    numsRows = 20;
    numsCols = 10;
    cellSize = 30;
    Initalise();
    colors = GetCellColors();
}

void Grid::Initalise()
{
    for (int row = 0; row < numsRows; row++)
    {
        for (int col = 0; col < numsCols; col++)
        {
            grid[row][col] = 0;
        }
    }
}

void Grid::display()
{
    for (int row = 0; row < numsRows; row++)
    {
        for (int col = 0; col < numsCols; col++)
        {
            std::cout << grid[row][col] << "\t";
        }
        std::cout << "\n";
    }
}

std::vector<Color> Grid::GetCellColors()
{
    Color darkGrey = {26, 31, 40, 255};
    Color green = {47, 230, 23, 255};
    Color red = {232, 18, 18, 255};
    Color orange = {226, 116, 17, 255};
    Color yellow = {237, 234, 4, 255};
    Color purple = {166, 0, 247, 255};
    Color cyan = {21, 204, 209, 255};
    Color blue = {13, 64, 216, 255};

    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}

/*
Syntax to draw a rectangle:
                void DrawRectangle(int posX, int posY, width, height, colour)
*/

void Grid::draw()
{
    for (int row = 0; row < numsRows; row++)
    {
        for (int column = 0; column < numsCols; column++)
        {
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}