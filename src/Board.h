//
// Created by Admin on 07.05.2023.
//

#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H
#include <vector>
#include <iostream>
#include <time.h>
#include <cstdlib>
#define WIELPOLE 30

class Board {
   int col;
   int row;
   std::vector<std::vector<int>> orchard;

public:
    Board(int width, int height);
    int getCols() const;
    int getRows() const;
    std::vector<int> spawnApple();
    void putApple();
    void removeApple(int);
    int getOrchardSize() const;
    int getAppleX(int) const ;
    int getAppleY(int) const ;
};


#endif //SNAKE_BOARD_H
