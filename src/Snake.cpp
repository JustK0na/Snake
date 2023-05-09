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

bool Snake::outOfBoard() const{
    if (getPosition()[0]<0||getPosition()[0]>(SIZE-1)||getPosition()[1]<0||getPosition()[1]>(SIZE-1))
    {
        return true;
    }
    return false;

}

std::vector<int> Snake::getPosition() const
{
    std::vector<int> tab{posX, posY};
    return tab;
}