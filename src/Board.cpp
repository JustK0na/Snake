//
// Created by Admin on 07.05.2023.
//

#include "Board.h"


Board::Board(int width, int height):col(width),row(height)
{
    level = MENU;
}

int Board::getRows() const {

    return row;
}
int Board::getCols() const {
    return col;
}
stage Board::getLevel() const {
    return level;
}
void Board::changeLevel(stage mode) {
    switch (mode) {
        case MENU:
            level = MENU;
            break;
        case GAME:
            level = GAME;
            break;
        case END:
            level = END;
    }
}
std::vector<int> Board::spawnApple()
{
    int x,y;
    x=rand()%24;
    y=rand()%24;

    std::vector<int> place;
    place.push_back(x);
    place.push_back(y);

    return place;
}

void Board::putApple() {
    std::vector<int> apple=spawnApple();
    orchard.push_back(apple);
   /* for(unsigned int i=0; i<orchard.size(); i++)
    {
        std::cout<<"\nJablka: ";
        for(int j=0; j<2; j++)
        {
            std::cout<<orchard[i][j]<<" ";
        }

    }*/
}
void Board::removeApple(int i)
{
    orchard.erase(orchard.begin()+i);
}
int Board::getOrchardSize() const
{
    return orchard.size();
}
int Board::getAppleX(int a) const
{
    return orchard[a][0];
}
int Board::getAppleY(int a) const
{
    return orchard[a][1];
}
