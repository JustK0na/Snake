//
// Created by Admin on 08.05.2023.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H
#include <vector>


enum direction{
    UP,
    DOWN,
    LEFT,
    RIGHT
};


class Snake {
    int posX;
    int posY;
    direction dir;

public:
    Snake(int x, int y);
    std::vector<int> getPosition() const;
    direction getDirection() const;
    void changeDirection(char key);
    void changeX(float x);
    void changeY(float y);
};


#endif //SNAKE_SNAKE_H
