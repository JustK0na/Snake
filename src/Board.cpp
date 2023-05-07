//
// Created by Admin on 07.05.2023.
//

#include "Board.h"


Board::Board(int thickness, int peak)
{
    width = thickness;
    height = peak;
}

int Board::getHeight() const {

    return height;
}
int Board::getWidth() const {
    return width;
}

