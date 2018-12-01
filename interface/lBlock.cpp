#include "lBlock.h"
#include "board.h"

using namespace::std;

lBlock::lBlock(int x, int y, int level, Board *board): Block{x, y, level, board} {
    numCells = 4;
    blockType = 'L';
}

bool lBlock::canRotate(int state){
    int x, y;

     if (state == 1) { //initial state is flat
        //collision check
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block
        bool cell1 = board->cellAt(x, y - 2)->cellFilled();
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block
        bool cell2 = board->cellAt(x - 1, y - 2)->cellFilled();

        //cell 1 and 2 fill in spaces cells 3 and 4 currently occupy

        if(cell1 || cell2) return false;
    }
    else if (state == 2){
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block
        bool cell1 = board->cellAt(x + 2, y + 1)->cellFilled();
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block
        bool cell2 = board->cellAt(x + 1, y)->cellFilled();
        if ( cell1 || cell2) return false;
    }
    else if (state == 3){
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block
        bool cell1 = board->cellAt(x, y - 2)->cellFilled();
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block
        bool cell2 = board->cellAt(x + 1, y - 1)->cellFilled();
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block
        bool cell4 = board->cellAt(x - 1, y + 1)->cellFilled();
        if (cell1 || cell2 || cell4) return false;
    }
    else {
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block
        bool cell1 = board->cellAt(x - 1, y)->cellFilled();
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block
        bool cell3 = board->cellAt(x + 1, y + 2)->cellFilled();
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block
        bool cell4 = board->cellAt(x + 2, y + 1)->cellFilled();

        if (cell1 || cell3 || cell4) return false; 
    }
    return true;
}

bool lBlock::canRotateCounter(int state){
    int x, y;

     if (state == 1) { //initial state is flat
        //collision check
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block
        bool cell2 = board->cellAt(x, y - 1)->cellFilled();
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block
        bool cell3 = board->cellAt(x - 1, y - 2)->cellFilled();
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block
        bool cell4 = board->cellAt(x - 2, y - 1)->cellFilled();

        //cell 1 and 2 fill in spaces cells 3 and 4 currently occupy

        if(cell2 || cell3 || cell4) return false;
    }
    else if (state == 2){
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block
        bool cell3 = board->cellAt(x + 2, y)->cellFilled();
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block
        bool cell4 = board->cellAt(x + 1, y - 1)->cellFilled();
        if ( cell3 || cell4) return false;
    }
    else if (state == 3){
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block
        bool cell1 = board->cellAt(x - 2, y - 1)->cellFilled();
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block
        bool cell4 = board->cellAt(x + 1, y)->cellFilled();
        if (cell1 || cell4) return false;
    }
    else {
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block
        bool cell1 = board->cellAt(x + 1, y - 1)->cellFilled();
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block
        bool cell3 = board->cellAt(x - 1, y + 1)->cellFilled();
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block
        bool cell4 = board->cellAt(x, y + 2)->cellFilled();
        if (cell1 || cell3 || cell4) return false; 
    }
    return true;
}

void lBlock::rotate(int state) {
    int x, y;
    if (state == 1) { //initial state is flat
        //block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x, y - 2);
        cells[0] = board->cellAt(x, y - 2);

        //block 2
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x - 1, y - 1);
        cells[1] = board->cellAt(x - 1, y - 1);

        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x - 2, y);
        cells[2] = board->cellAt(x - 2, y);

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x - 1, y + 1);
        cells[3] = board->cellAt(x - 1, y + 1);


    }
    else if (state == 2){
        //block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x + 2, y + 1);
        cells[0] = board->cellAt(x + 2, y + 1);

        //block 2
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x + 1, y);
        cells[1] = board->cellAt(x + 1, y);

        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x, y - 1);
        cells[2] = board->cellAt(x, y - 1);

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x - 1, y);
        cells[3] = board->cellAt(x - 1, y);

    }
    else if (state == 3){
        //block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x - 1, y + 1);
        cells[0] = board->cellAt(x - 1, y + 1);

        //block 2 pivot

        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x + 1, y - 1);
        cells[2] = board->cellAt(x + 1, y - 1);

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x, y - 2);
        cells[3] = board->cellAt(x, y - 2);
    }
    else if (state == 4){
        //block 1
        x = cells[0]->get_X();
        y = cells[0]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x - 1, y);
        cells[0] = board->cellAt(x - 1, y);

        //block 2 pivot
        x = cells[1]->get_X();
        y = cells[1]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x, y + 1);
        cells[1] = board->cellAt(x, y + 1);

        //block 3
        x = cells[2]->get_X();
        y = cells[2]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x + 1, y + 2);
        cells[2] = board->cellAt(x + 1, y + 2);

        //block 4
        x = cells[3]->get_X();
        y = cells[3]->get_Y(); //pos of block

        if(board->cellAt(x, y)->cellFilled()) board->unset(x, y);
        board->set(x + 2, y + 1);
        cells[3] = board->cellAt(x + 2, y + 1);
    }
}

void lBlock::rotateClockwise() {
    int x0 = cells[0]->get_X();
    int x3 = cells[3]->get_X();
    if ( (rotateState == 2) && (x0 > 8)) return;
    if ( (rotateState == 4) && (x3 > 8)) return;
    rotate(rotateState);
    if (rotateState == 4) rotateState = 1;
    else rotateState++;
    applyDropSpeed();
}

void lBlock::rotateCounterClockwise() {
    int loop = 3;
    while (loop) {
        rotate(rotateState);
        if (rotateState == 4) rotateState = 1;
        else rotateState++;
        loop--;
    }
    applyDropSpeed();
}