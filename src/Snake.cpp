//
// Created by Admin on 08.05.2023.
//

#include "Snake.h"

Snake::Snake(int x, int y):posX(x), posY(y)
{
    dir = RIGHT;
}
direction Snake::getDirection() const
{
    return dir;
}
void Snake::changeX(float x)
{
    posX=posX+x;
}
void Snake::changeY(float y)
{
    posY=posY+y;
}
void Snake::changeDirection(char key)
{
    switch (key) {
        case 'w':
            dir=UP;
            break;
        case 'd':
            dir=RIGHT;
            break;
        case 's':
            dir=DOWN;
            break;
        case 'a':
            dir=LEFT;
            break;
    }
}

std::vector<int> Snake::getPosition() const
{
    std::vector<int> tab{posX, posY};
    return tab;
}