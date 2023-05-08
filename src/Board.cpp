//
// Created by Admin on 07.05.2023.
//

#include "Board.h"


Board::Board(int width, int height):col(width),row(height)
{
}

int Board::getRows() const {

    return row;
}
int Board::getCols() const {
    return col;
}

