//
// Created by Admin on 08.05.2023.
//

#include "View.h"

#define WIELPOLE 30



View::View(std::vector<Board> &board, SnakeBody &snake):b(board),s(snake)
{}

void View::drawApples(sf::RenderWindow &window) const {
    if (b[0].getLevel() == GAME||b[0].getLevel() == CUBE) {
        sf::RectangleShape rect(sf::Vector2f(WIELPOLE, WIELPOLE));
        for (signed i = 0; i < b[0].getOrchardSize(); i++) {
            rect.setPosition(MARGINES  + WIELPOLE * b[0].getAppleX(i), GUI  + WIELPOLE * b[0].getAppleY(i));
            rect.setOutlineThickness(2);
            rect.setOutlineColor(sf::Color(168, 55, 49));

            rect.setFillColor(sf::Color(244, 87, 80));
            window.draw(rect);
        }
    }
}
void View::drawBackground(sf::RenderWindow &window) const
{
    if(b[0].getLevel()!=MENU) {
        int board = s.getPosition(0)[2];
        sf::RectangleShape rect(sf::Vector2f(WIELPOLE, WIELPOLE));
        for (int i = 0; i < b[0].getRows(); i++)
            for (int j = 0; j < b[0].getCols(); ++j) {
                rect.setPosition(MARGINES + j * WIELPOLE + 1, GUI + i * WIELPOLE + 1);
                rect.setOutlineThickness(2);
                rect.setOutlineColor(sf::Color(148, 132, 22));

                rect.setFillColor(sf::Color(255-board*40, 245-board*10, 176+board*10));
                window.draw(rect);
            }
    }
}

void View::drawSnake(sf::RenderWindow &window) const {
    if(b[0].getLevel()!=MENU) {
        int board=s.getPosition(0)[2];

        for (int i = 0; i < s.getSnakeSize(); i++) {
            if(board==s.getPosition(i)[2])
            {
                sf::RectangleShape rect(sf::Vector2f(WIELPOLE - 4, WIELPOLE - 4));
                rect.setPosition((WIELPOLE * s.getPosition(i)[0]) + MARGINES + 2, WIELPOLE * s.getPosition(i)[1] + GUI + 2);

                if (i == 0)
                    rect.setFillColor(sf::Color(22, 168, 78));
                else if (i != 0)
                    rect.setFillColor(sf::Color(81, 245, 143));
                window.draw(rect);
            }

        }
    }
 }
void View::Highlight(Texts texts)
{
    switch (texts) {
        case CLASSICTEXT:
            highlight = CLASSICTEXT;
            break;
        case CUBETEXT:
            highlight = CUBETEXT;
            break;
        case EXITTEXT:
            highlight = EXITTEXT;
             break;
        case NOTHINGTEXT:
            highlight = NOTHINGTEXT;

        default:
            break;

    }
}
void View::writeText(sf::RenderWindow &window) const {
    sf::Font font;
    sf::Text text, text2, text3, text4, text5 ;
    font.loadFromFile("../Graphics/Font/PixelCode.otf");
    text.setFont(font);
    text.setCharacterSize(24);
    if(b[0].getLevel()==MENU)
    {
        //SNAKE
        text.setCharacterSize(90);
        text.setString("SNAKE");
        text.setFillColor(sf::Color(83, 194, 78));
        text.setPosition(MARGINES+b[0].getCols()/2*WIELPOLE-140,GUI-30);

        //CLASSIC
        text2.setFont(font);
        text2.setCharacterSize(72);
        text2.setString("CLASSIC");
        text2.setFillColor(sf::Color(83, 194, 78));
        text2.setPosition(MARGINES+b[0].getCols()/2*WIELPOLE-160,GUI+130);
        if(highlight==CLASSICTEXT)
            text2.setPosition(text2.getPosition().x,text2.getPosition().y-30);
        window.draw(text2);

        //CUBE
        text3.setFont(font);
        text3.setCharacterSize(72);
        text3.setString("CUBE");
        text3.setFillColor(sf::Color(83, 194, 78));
        text3.setPosition(MARGINES+b[0].getCols()/2*WIELPOLE-110,GUI+230);
        sf::RectangleShape rect(sf::Vector2f(40,40));
        rect.setPosition(MARGINES+b[0].getCols()/2*WIELPOLE+95,GUI+257);
        rect.setOutlineThickness(5);
        rect.setOutlineColor(sf::Color(83, 194, 78));
        rect.setFillColor(sf::Color(106, 83, 245));
        if(highlight==CUBETEXT)
        {
            text3.setPosition(text3.getPosition().x,text3.getPosition().y-30);
            rect.setPosition(rect.getPosition().x,rect.getPosition().y-30);
        }
        window.draw(rect);
        window.draw(text3);


        //EXIT
        text4.setFont(font);
        text4.setCharacterSize(90);
        text4.setString("EXIT");
        text4.setFillColor(sf::Color(83, 194, 78));
        text4.setPosition(MARGINES+b[0].getCols()/2*WIELPOLE-90,GUI+530);
        if(highlight==EXITTEXT)
            text4.setPosition(text4.getPosition().x,text4.getPosition().y-30);
        window.draw(text4);




    }
    else if(b[0].getLevel()==END)
    {
        text.setString("You crashed :/  press any button to restart..");
        text.setFillColor(sf::Color(186, 15, 66));
        text.setPosition(MARGINES,GUI-30);
    }
    else if(b[0].getLevel()!=MENU)
    {
        text.setCharacterSize(35);
        text.setString(std::to_string(s.getSnakeSize()));
        text.setFillColor(sf::Color(23, 4, 148));
        text.setPosition(MARGINES+SIZE/2*WIELPOLE,GUI/2);
    }


    window.draw(text);
}
void View::present(sf::RenderWindow &window) const
{

    window.clear(sf::Color(106, 83, 245));

        drawBackground(window);
        drawApples(window);
        drawSnake(window);
        writeText(window);




    window.display();

}