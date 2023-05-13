//
// Created by Admin on 08.05.2023.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#define SIZE 25

#include <vector>




enum direction{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct cell{
    float posX;
    float posY;
    direction dir;
};
class Snake {
    float posX;
    float posY;
    direction dir;

public:
    Snake(int x, int y);
    std::vector<int> getPosition() const;
    direction getDirection() const;
    void changeDirection(char key);
    void changeX(float x);
    void changeY(float y);
    bool outOfBoard() const;
};

class SnakeBody{
    std::vector<cell> body;
public:
    SnakeBody(int x, int y);
    std::vector<int> getHeadPosition() const;
    direction getDirection() const;
    int getSnakeSize() const;
    void changeDirection(char key);
    void changeX(float x);
    void changeY(float y);
    bool outOfBoard() const;
    void snakeGrow() ;  //!!!!!!!!!!!!!!!!!!!!!!!!!
};


#endif //SNAKE_SNAKE_H
