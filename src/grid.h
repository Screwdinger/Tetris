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
    bool IsCellOutside(int row, int column);
    int grid[20][10];
    void draw();
};