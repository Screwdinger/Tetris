#include "grid.h"
#include<iostream>

Grid::Grid()
{
    numsRows = 20;
    numsCols = 10;
    cellSize = 30;
    Initalise();
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
            std::cout<<grid[row][col]<<"\t";
        }
        std::cout<<"\n";
    }
}