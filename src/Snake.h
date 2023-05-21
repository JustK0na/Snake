//
// Created by Admin on 08.05.2023.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#define SIZE 25

#include <vector>
#include <cmath>
#include <iostream>
#define FRAMERATE 15





/*
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
*/
enum direction{
    UP,
    DOWN,
    LEFT,
    RIGHT
};
enum edge
{
    TOP_EDGE,
    BOTTOM_EDGE,
    LEFT_EDGE,
    RIGHT_EDGE,
    NO_EDGE
};

struct cell{
    int posX;
    int posY;
    direction dir;
    int board;
};
class SnakeBody{
    std::vector<cell> body;
    int clock;
public:
    SnakeBody(int x, int y);
    std::vector<int> getPosition(int i) const;
    direction getDirection(int i) const;
    int getSnakeSize() const;
    int getClock() const;
    edge outOfBoard() const;
    void changeDirection(char key);
    void changeX(float x);
    void changeY(float y);
    void changeBoard(edge);
    void addClock();
    void resetSnake();

    void snakeGrow() ;  //!!!!!!!!!!!!!!!!!!!!!!!!!
};


#endif //SNAKE_SNAKE_H
