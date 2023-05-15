//
// Created by Admin on 08.05.2023.
//

#include "View.h"

#define WIELPOLE 30


View::View(Board &board, SnakeBody &snake):b(board),s(snake)
{}
void View::drawApples(sf::RenderWindow &window) const
{
    sf::RectangleShape rect(sf::Vector2f(WIELPOLE,WIELPOLE));
    for(signed i=0; i<b.getOrchardSize(); i++)
    {
        rect.setPosition(MARGINES+1+WIELPOLE*b.getAppleX(i),GUI+1+WIELPOLE*b.getAppleY(i));
        rect.setOutlineThickness(2);
        rect.setOutlineColor(sf::Color(15, 75, 133));

        rect.setFillColor(sf::Color(199, 65, 42));
        window.draw(rect);
    }
}
void View::drawBackground(sf::RenderWindow &window) const
{
   sf::RectangleShape rect(sf::Vector2f(WIELPOLE,WIELPOLE));
   for(int i=0; i<b.getRows(); i++)
       for (int j = 0; j < b.getCols(); ++j) {
           rect.setPosition(MARGINES+j*WIELPOLE+1,GUI+i*WIELPOLE+1);
           rect.setOutlineThickness(2);
           rect.setOutlineColor(sf::Color(15, 75, 133));

           rect.setFillColor(sf::Color(19, 109, 194));
           window.draw(rect);
       }

}

void View::drawSnake(sf::RenderWindow &window) const {
    for(int i=0; i<s.getSnakeSize(); i++)
    {
        sf::RectangleShape rect(sf::Vector2f(WIELPOLE-4, WIELPOLE-4));
        rect.setPosition((WIELPOLE*s.getPosition(i)[0])+MARGINES+2, WIELPOLE*s.getPosition(i)[1]+GUI+2);

        if(i==0)
        {
            rect.setFillColor(sf::Color(42, 99, 15));
        }
        else if(i!=0)
            rect.setFillColor(sf::Color(73, 173, 26));
        window.draw(rect);
    }
 }
void View::present(sf::RenderWindow &window) const
{

    window.clear(sf::Color(135, 191, 239));
    drawBackground(window);
    drawApples(window);
    drawSnake(window);

    window.display();

}