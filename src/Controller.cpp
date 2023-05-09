//
// Created by Admin on 08.05.2023.
//

#include "Controller.h"

Controller::Controller(Board &board, Snake &snake):b(board),s(snake)
{}

void Controller::movementChange(sf::Event &event) {

    switch (event.key.code) {
        case sf::Keyboard::W:
            s.changeDirection('w');
            break;
        case sf::Keyboard::D:
            s.changeDirection('d');
            break;
        case sf::Keyboard::S:
            s.changeDirection('s');
            break;
        case sf::Keyboard::A:
            s.changeDirection('a');
            break;
        default:
            break;


    }
}
void Controller::movement(direction dir)
{
    float wielnapole=WIELNAPOLE;
    float framerate = FRAMERATE;
    float VELOCITY = ((wielnapole/5)/framerate);//

              //Wolno zakręcać tylko wtedy gdy waz jest na całkowitym polu,
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
    std::cout<<"\nwasz X: "<<s.getPosition()[0]<<"\twasz Y: "<<s.getPosition()[1]<<"\tVelocity: "<<VELOCITY;
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
    movement(s.getDirection());
}