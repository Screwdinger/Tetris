#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
    std::vector<Block> blocks;
    Block currentBlock;
    Block previousBlock;
    bool IsBlockOutside();
    void RotateBlock();

    public:
    Game();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void Draw();
    void HandleInput();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    Grid grid;
};