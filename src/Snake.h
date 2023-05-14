//
// Created by Admin on 08.05.2023.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#define SIZE 25

#include <vector>
#include <cmath>
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

struct cell{
    int posX;
    int posY;
    direction dir;
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
    bool outOfBoard() const;
    void changeDirection(char key);
    void changeX(float x);
    void changeY(float y);
    void addClock();

    void snakeGrow() ;  //!!!!!!!!!!!!!!!!!!!!!!!!!
};


#endif //SNAKE_SNAKE_H
