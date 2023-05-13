//
// Created by Admin on 08.05.2023.
//

#include "Snake.h"
/*
 * ##########################
 * STARY SNAKE JAKO PUNKT  ##
 * ##########################
 *
 */



/*
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
}*/

/*########################################################
#                                                        #
#                   SNAKE VECTOR                         #
#                                                        #
##########################################################*/

SnakeBody::SnakeBody(int x, int y)
{
    cell head;
    body.push_back(head);
    body.front().posX=x;
    body.front().posY=y;
    body.front().dir=RIGHT;
}
std::vector<int> SnakeBody::getHeadPosition() const
{
    std::vector<int> tab{int(body.front().posX), int(body.front().posY)};
    return tab;
}
direction SnakeBody::getDirection() const
{
    return body.front().dir;
}
int SnakeBody::getSnakeSize() const
{
    return body.size();
}
void SnakeBody::changeDirection(char key)
{
    for(int i=(body.size()-1); i>0; i--)
    {
        body.at(i).dir = body.at(i-1).dir;
    }
    switch (key) {
        case 'w':
            body.front().dir=UP;
            break;
        case 'd':
            body.front().dir=RIGHT;
            break;
        case 's':
            body.front().dir=DOWN;
            break;
        case 'a':
            body.front().dir=LEFT;
            break;
    }
}
void SnakeBody::changeX(float x)
{
    for(int i=(body.size()-1); i>0; i--)
    {
        body.at(i).posX = body.at(i-1).posX;
    }
    body.front().posX=body.front().posX+x;
}
void SnakeBody::changeY(float y)
{

    for(int i=(body.size()-1); i>0; i--)
    {
        body.at(i).posY = body.at(i-1).posY;
    }

    body.front().posY=body.front().posY+y;
}
bool SnakeBody::outOfBoard() const{
    if (getHeadPosition()[0]<0||getHeadPosition()[0]>(SIZE-1)||getHeadPosition()[1]<0||getHeadPosition()[1]>(SIZE-1))
    {
        return true;
    }
    return false;

}
void  SnakeBody::snakeGrow()
{
    cell bodyPart;

    body.push_back(bodyPart);

}