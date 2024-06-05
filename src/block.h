#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block
{
    int cellSize;
    int rotationState;
    int rowOffset;
    int columnOffset;
    std::vector<Color> colors;

public:
    Block();
    void Draw();
    void Rotate();
    void UndoRotate();
    void Move(int rows, int columns);
    std::vector<Position> GetCellPositions();
    int id;
    std::map<int, std::vector<Position>> cells;
};