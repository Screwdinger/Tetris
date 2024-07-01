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

bool Grid::IsCellOutside(int row, int column)
{
    if (row >= 0 && row < numsRows && column >= 0 && column < numsCols)
    {
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
    if (grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

bool Grid::IsRowFull(int row)
{
    for (int column = 0; column < numsCols; column++)
    {
        if (grid[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for (int column = 0; column < numsCols; column++)
    {
        grid[row][column] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows)
{
    for (int column = 0; column < numsCols; column++)
    {
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for(int row = numsRows - 1; row >= 0; row--)
    {
        if(IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if(completed > 0)
        {
            MoveRowDown(row, completed);
        }
    }
    return completed;
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
            DrawRectangle(column * cellSize + 11, row * cellSize + 11   , cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}