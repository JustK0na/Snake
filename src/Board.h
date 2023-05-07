//
// Created by Admin on 07.05.2023.
//

#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H


class Board {
   int width;
   int height;


public:
    Board(int width, int height);
    int getWidth() const;
    int getHeight() const;
};


#endif //SNAKE_BOARD_H
