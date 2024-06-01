#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
    int numsRows;
    int numsCols;
    int cellSize;
    std::vector<Color> colors;

public:
    Grid();
    void Initalise();
    void display();
    int grid[20][10];
    std::vector<Color> GetCellColors();
    void draw();
};