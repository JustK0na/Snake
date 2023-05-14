//
// Created by Admin on 08.05.2023.
//

#include "Controller.h"

Controller::Controller(Board &board, SnakeBody &snake):b(board),s(snake)
{}

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
    float wielnapole = WIELNAPOLE;
    float framerate = FRAMERATE;
    float VELOCITY =((5)/framerate);//
    //Wolno zakręcać tylko wtedy gdy waz jest na całkowitym polu,
    if(s.outOfBoard())
    {
        return;
    }
    for(int i=0; i<s.getSnakeSize(); i++)
    {
        direction dir = s.getDirection(i);
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
    }

    std::cout<<"\nwasz X: "<<s.getPosition(0)[0]<<"\twasz Y: "<<s.getPosition(0)[1]<<"\tVelocity: "<<VELOCITY;
}

void Controller::addPoint(sf::Event &event)
{
    switch (event.key.code) {
        case sf::Keyboard::J :
            s.snakeGrow();
            std::cout<<"\nWielkosc weza: "<<s.getSnakeSize();
            break;
        default:
            break;
    }

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
                addPoint(event);
                break;

            default:
                break;
        }

    }
    movement();
}