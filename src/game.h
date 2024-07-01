#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    bool IsBlockOutside();
    bool BlockFits();
    void RotateBlock();
    void LockBlock();
    void Reset();
    void MoveBlockLeft();
    void MoveBlockRight();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void UpdateScore(int LinesCleared, int moveDownPoints);
    Grid grid;
    Sound rotateSound;
    Sound clearSound;

public:
    Game();
    ~Game();
    bool gameOver;
    int score;
    Music music;
    void Draw();
    void HandleInput();
    void MoveBlockDown();
};