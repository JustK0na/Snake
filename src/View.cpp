//
// Created by Admin on 08.05.2023.
//

#include "View.h"

#define WIELPOLE 30
#define MARGINES 20
#define  GUI 200

View::View(Board &board, SnakeBody &snake):b(board),s(snake)
{}
void View::drawBackground(sf::RenderWindow &window) const
{
   sf::RectangleShape rect(sf::Vector2f(WIELPOLE,WIELPOLE));
   for(int i=0; i<b.getRows(); i++)
       for (int j = 0; j < b.getCols(); ++j) {
           rect.setPosition(MARGINES+j*WIELPOLE,GUI+i*WIELPOLE);
           rect.setOutlineThickness(2);
           rect.setOutlineColor(sf::Color(15, 75, 133));
           rect.setFillColor(sf::Color(19, 109, 194));
           window.draw(rect);
       }

}

void View::drawSnake(sf::RenderWindow &window) const {
    for(int i=0; i<s.getSnakeSize(); i++)
    {
       static sf::RectangleShape rect(sf::Vector2f(WIELPOLE-2, WIELPOLE-2));
        rect.setPosition((WIELPOLE*s.getPosition(i)[0])+MARGINES, WIELPOLE*s.getPosition(i)[1]+GUI);
        rect.setFillColor(sf::Color(73, 173, 26));
        window.draw(rect);
    }
   // sf::RectangleShape rect(sf::Vector2f(WIELPOLE-2, WIELPOLE-2));

    /*rect.setPosition((WIELPOLE*s.getHeadPosition()[0])+MARGINES, WIELPOLE*s.getHeadPosition()[1]+GUI);
    rect.setFillColor(sf::Color(73, 173, 26));*/



}
void View::present(sf::RenderWindow &window) const
{

    window.clear(sf::Color(95, 167, 237));
    drawBackground(window);
    drawSnake(window);
    window.display();

}