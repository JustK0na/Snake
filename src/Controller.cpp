//
// Created by Admin on 08.05.2023.
//

#include "Controller.h"


Controller::Controller(std::vector<Board> &board, SnakeBody &snake, View &view):b(board),s(snake),v(view)
{

}

void Controller::movementChange(sf::Event &event) {

    switch (event.key.code) {
        case sf::Keyboard::W:
            if(s.getDirection(0)==DOWN)
                return;
            s.changeDirection('w');
            break;
        case sf::Keyboard::D:
            if(s.getDirection(0)==LEFT)
                return;
            s.changeDirection('d');
            break;
        case sf::Keyboard::S:
            if(s.getDirection(0)==UP)
                return;
            s.changeDirection('s');
            break;
        case sf::Keyboard::A:
            if(s.getDirection(0)==RIGHT)
                return;
            s.changeDirection('a');
            break;
        default:
            break;


    }
}
void Controller::movement()
{
    float VELOCITY = 7;
    if(b[0].getLevel()==GAME) {
        if (s.outOfBoard()!=NO_EDGE) {
            b[0].changeLevel(END);
            return;
        }
    }
    else if(b[0].getLevel()==CUBE)
    {
        if (s.outOfBoard()==RIGHT_EDGE) {
            s.changeBoard(RIGHT_EDGE);
        }
        if(s.outOfBoard()==LEFT_EDGE){
            s.changeBoard(LEFT_EDGE);
        }
    }
    if(checkCollision())
    {
        b[0].changeLevel(END);
        return;
    }
    if(b[0].getLevel()==MENU||b[0].getLevel()==END)
    {
        return;
    }
        direction dir = s.getDirection(0);
        switch (dir) {
            case UP:
                s.changeY((-VELOCITY));
                break;
            case DOWN:
                s.changeY(VELOCITY);
                break;
            case LEFT:
                s.changeX((-VELOCITY));
                break;
            case RIGHT:
                s.changeX(VELOCITY);
                break;


        }
    std::cout<<"\nBOARD: ";
    for(unsigned int i = 0; i<s.getSnakeSize(); i++)
    {
        std::cout<<s.getPosition(i)[2]<<" ";
    }
}

void Controller::addPoint()
{
    for(signed int i=0; i<b[0].getOrchardSize(); i++)
    {
        if(s.getPosition(0)[0]==b[0].getAppleX(i)&&s.getPosition(0)[1]==b[0].getAppleY(i))
        {
            s.snakeGrow();
            b[0].removeApple(i);
        }
    }
}
void Controller::spawnApple()
{
    if(b[0].getLevel()==MENU||b[0].getLevel()==END)
    {
        time =0;
        return;
    }
    if(time>=FRAMERATE*5)
    {
        if(b[0].getLevel()==GAME)
        {
            b[0].putApple();
            time=0;
            return;
        }
        if(b[0].getLevel()==CUBE)
        {
            for(unsigned int i=0; i<b.size(); i++)
            {
                b.at(i).putApple();
            }
            time =0;
            return;
        }

    }
    time++;
}
bool Controller::checkCollision() const
{
    for(int i=2; i<s.getSnakeSize(); i++)//i =2 bo glowa i pierwszy element nigdy nie uderzy
    {
        if(s.getPosition(0)[0]==s.getPosition(i)[0]&&s.getPosition(0)[1]==s.getPosition(i)[1]&&s.getPosition(0)[2]==s.getPosition(i)[2])//Pozycja X, Y i plansza
        {
            return true;
        }
    }
    return false;
}
void Controller::clickAnyButton()
{
    if (b[0].getLevel()==GAME)
        return;
  /*  else if(b[0].getLevel()==MENU)
        b[0].changeLevel(GAME);*/

    if(b[0].getLevel()==END)
    {
        b[0].changeLevel(MENU);
        s.resetSnake();
        for(unsigned int i=0; i<b.size(); i++)
            b[i].resetBoard();
    }

}
void Controller::menuClick(sf::Event &event, sf::RenderWindow &win) {
    if (event.mouseButton.button == sf::Mouse::Left) {
        if (sf::Mouse::getPosition(win).x > MARGINES + b[0].getCols() / 2 * WIELPOLE - 160 &&
            sf::Mouse::getPosition(win).x < MARGINES + b[0].getCols() / 2 * WIELPOLE + 180) {
            if (sf::Mouse::getPosition(win).y > 345 &&
                sf::Mouse::getPosition(win).y < 402) //Ustalone metoda prób i błędów
            {
                std::cout << "\nClassic";
                b[0].changeLevel(GAME);
            }

        }
        if (sf::Mouse::getPosition(win).x > MARGINES + b[0].getCols() / 2 * WIELPOLE - 110 &&
            sf::Mouse::getPosition(win).x < MARGINES + b[0].getCols() / 2 * WIELPOLE + 140) {
            if (sf::Mouse::getPosition(win).y > 440 &&
                sf::Mouse::getPosition(win).y < 500) //Ustalone metoda prób i błędów
            {
                std::cout << "\nCube";
                b[0].changeLevel(CUBE);
            }
        }
        if (sf::Mouse::getPosition(win).x > MARGINES + b[0].getCols() / 2 * WIELPOLE - 85 &&
            sf::Mouse::getPosition(win).x < MARGINES + b[0].getCols() / 2 * WIELPOLE + 150) {
            if (sf::Mouse::getPosition(win).y > 750 &&
                sf::Mouse::getPosition(win).y < 820) //Ustalone metoda prób i błędów
            {
                std::cout << "\nExit";
                win.close();
            }

        }

    }
}
void Controller::menuHighlit(sf::Event &, sf::RenderWindow &win)
{
    if(sf::Mouse::getPosition(win).x>MARGINES+b[0].getCols()/2*WIELPOLE-160&&sf::Mouse::getPosition(win).x<MARGINES+b[0].getCols()/2*WIELPOLE+180)
    {
        if(sf::Mouse::getPosition(win).y>345&&sf::Mouse::getPosition(win).y<402) //Ustalone metoda prób i błędów
        {
            v.Highlight(CLASSICTEXT);
            std::cout<<"\nHighlight classicText";
            return;
        }

    }
    if (sf::Mouse::getPosition(win).x > MARGINES + b[0].getCols() / 2 * WIELPOLE - 110 &&
        sf::Mouse::getPosition(win).x < MARGINES + b[0].getCols() / 2 * WIELPOLE + 140) {
        if (sf::Mouse::getPosition(win).y > 440 &&
            sf::Mouse::getPosition(win).y < 500) //Ustalone metoda prób i błędów
        {
            v.Highlight(CUBETEXT);
            std::cout<<"\nHighlight CubeText";
            return;
        }
    }
    if(sf::Mouse::getPosition(win).x>MARGINES+b[0].getCols()/2*WIELPOLE-85 && sf::Mouse::getPosition(win).x<MARGINES+b[0].getCols()/2*WIELPOLE+150)
    {
        if(sf::Mouse::getPosition(win).y>750&&sf::Mouse::getPosition(win).y<820) //Ustalone metoda prób i błędów
        {
            v.Highlight(EXITTEXT);
            std::cout<<"\nHighlight ExitText";
            return;
        }

    }
    v.Highlight(NOTHINGTEXT);
    return;
}
void Controller::control(sf::RenderWindow &win)
{
    sf::Event event;
    while (win.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                win.close();
                break;
            case sf::Event::KeyPressed:
                movementChange(event);
                clickAnyButton();
                break;
            case sf::Event::MouseButtonPressed:
                menuClick(event, win);
                break;
            case sf::Event::MouseMoved:
                menuHighlit(event, win);
            default:
                break;
        }

    }
    movement();
    spawnApple();
    addPoint();
    checkCollision();
}