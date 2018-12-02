#ifndef __BOARD_H__
#define __BOARD_H__
#include <vector>
#include "cell.h"
#include "block.h"
#include "window.h"

class Board {
    std::vector<std::vector<Cell>> grid; //NEED TO FIX, ARRAY OF CELL POINTERS NOW
    int x;
    int y;
    Block* currBlock;
    Block *nextBlock;
    std::vector<Block *> loBlock;
    Xwindow * win;
    //Xwindow window;

    public:
    Board(int x, int y, Xwindow * win);
    ~Board();
    void init();
    void reset();
    void clearRow(int row);
    int checkRows();
    Cell *cellAt(int x, int y);
    void set(int x, int y);
    void unset(int x, int y);
    Block * getCurrBlock();
    Block * initBlock(char type);
    void addBlock(Block *b);
    void removeCells();
    void set_next_block();
    int count_score();
    void set_blocks(Block * currBlock, Block * nextBlock);
    void blind();
    void unblind();
    std::vector<Cell> getline(int i);
    bool canFit(char blockType);
    bool canFitNew(char blockType);
    bool swapBlock(char blockType);
    void dropStar(int level);



   // void setCurrBlock(Block *currBlock);
    friend std::ostream& operator<<(std::ostream& os, Board& board);



};

std::ostream& operator<<(std::ostream& os, Board& board);


#endif