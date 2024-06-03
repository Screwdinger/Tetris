#include "grid.h"
#include <iostream>
#include "colors.h"

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