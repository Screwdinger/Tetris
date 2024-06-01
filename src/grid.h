#pragma once

class Grid
{
    int numsRows;
    int numsCols;
    int cellSize;

    public:
    Grid();
    void Initalise();
    void display();
    int grid[20][10];
};