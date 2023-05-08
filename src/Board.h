//
// Created by Admin on 07.05.2023.
//

#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H
#include <vector>


#define WIELPOLE 30

class Board {
   int col;
   int row;
   //std::vector<std::vector<int>> tab;


public:
    Board(int width, int height);
    int getCols() const;
    int getRows() const;
};


#endif //SNAKE_BOARD_H
