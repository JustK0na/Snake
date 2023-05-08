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
    float posX;
    float posY;
    direction dir;

public:
    Snake(float x, float y);
    std::vector<float> getPosition() const;
    direction getDirection() const;
    void changeDirection(char key);
    void changeX(float x);
    void changeY(float y);
};


#endif //SNAKE_SNAKE_H
