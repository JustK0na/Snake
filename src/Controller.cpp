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
    float VELOCITY = 5;
    if(s.outOfBoard())
    {
        return;
    }
   // for(int i=0; i<s.getSnakeSize(); i++)
    //{
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
   // }

    //std::cout<<"\nwasz0 X: "<<s.getPosition(0)[0]<<"\twasz0 Y: " <<s.getPosition(0)[1]<<"\twasz1 X: "<<s.getPosition(1)[0]<<"\twasz1 Y: "<<s.getPosition(1)[1];
}

void Controller::addPoint()
{
    for(signed int i=0; i<b.getOrchardSize(); i++)
    {
        if(s.getPosition(0)[0]==b.getAppleX(i)&&s.getPosition(0)[1]==b.getAppleY(i))
        {
            s.snakeGrow();
            b.removeApple(i);
        }
    }
}
void Controller::spawnApple()
{
    if(time>=FRAMERATE*7)
    {
        b.putApple();
        time=0;
        return;
    }
    time++;
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

                break;

            default:
                break;
        }

    }
    movement();
    spawnApple();
    addPoint();
}