//
// Created by Admin on 08.05.2023.
//

#include "Snake.h"
SnakeBody::SnakeBody(int x, int y)
{
    cell head;
    body.push_back(head);
    body.front().posX=x;
    body.front().posY=y;
    body.front().dir=RIGHT;
    body.front().board=0;
    clock = 1;
}
std::vector<int> SnakeBody::getPosition(int i) const
{
    std::vector<int> tab{int(body[i].posX), int(body[i].posY), body[i].board};
    return tab;
}
direction SnakeBody::getDirection(int i) const
{
    return body.at(i).dir;
}
int SnakeBody::getSnakeSize() const
{
    return body.size();
}
void SnakeBody::changeDirection(char key)
{
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
void SnakeBody::resetSnake() {
    body.front().posX = SIZE/2;
    body.front().posY = SIZE/2;
    body.front().dir = RIGHT;

    int size = body.size();
    body.erase(body.begin()+1,body.begin()+size);
}
void SnakeBody::changeX(float x)
{
    int modulusx = sqrt(pow(x,2));
    if(clock!=FRAMERATE/modulusx)
    {
        clock++;
        return;
    }



    for(int i=(body.size()-1); i>0; i--)
    {
        body.at(i).posX=body.at(i-1).posX;
        body.at(i).posY=body.at(i-1).posY;
        body.at(i).board=body.at(i-1).board;
    }
    body.front().posX=body.front().posX+x/modulusx;
    clock=1;

}
void SnakeBody::changeY(float y)
{
    int modulusy = sqrt(pow(y,2));
    if(clock!=FRAMERATE/modulusy)
    {
        clock++;
        return;
    }
    for(int i=(body.size()-1); i>0; i--)
    {
        body.at(i).posX=body.at(i-1).posX;
        body.at(i).posY=body.at(i-1).posY;
        body.at(i).board=body.at(i-1).board;
    }
    body.front().posY=body.front().posY+y/modulusy;



    clock=1;

}
void SnakeBody::changeBoard(edge e)
{

            if(e==RIGHT_EDGE)
            {
                if(body.front().board>=0&&body.front().board<3) {
                    body.front().board++;
                    body.front().posX = 0;
                }
                else
                {
                    body.front().board = 0;
                    body.front().posX = 0;
                }
            }
            if(e==LEFT_EDGE)
            {
                if(body.front().board>0&&body.front().board<=3) {
                    body.front().board--;
                    body.front().posX = SIZE - 1;
                }
                else
                {
                    body.front().board = 3;
                    body.front().posX = SIZE - 1;
                }
            }
            if(e==TOP_EDGE)
            {
                
            }
            if(e==BOTTOM_EDGE)
            {

            }
}
edge SnakeBody::outOfBoard() const{
    if (getPosition(0)[0]<0)
    {
        return LEFT_EDGE;
    }
    if(getPosition(0)[0]>(SIZE-1))
    {
        return RIGHT_EDGE;
    }
    if(getPosition(0)[1]<0)
    {
        return TOP_EDGE;
    }
    if(getPosition(0)[1]>(SIZE-1))
    {
        return BOTTOM_EDGE;
    }
    return NO_EDGE;

}
void  SnakeBody::snakeGrow()
{
    cell bodyPart;
    bodyPart.posX=body.back().posX;
    bodyPart.posY=body.back().posY;
    bodyPart.board=body.back().board;
    body.push_back(bodyPart);

}
void SnakeBody::addClock()
{
    clock++;
}

int SnakeBody::getClock() const
{
    return clock;
}