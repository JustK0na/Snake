//
// Created by Admin on 08.05.2023.
//

#ifndef SNAKE_CONTROLLER_H
#define SNAKE_CONTROLLER_H

#define FRAMERATE 15.0f
#define WIELNAPOLE 30.0f
#define VELOCITY  ((WIELNAPOLE/FRAMERATE)/4)

#include "Board.h"
#include "Snake.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
class Controller {

    Board &b;
    Snake &s;
public:
    Controller(Board &board, Snake &snake);
    void control(sf::RenderWindow &win);
    void movementChange(sf::Event &event);
    void movement(direction dir);

};


#endif //SNAKE_CONTROLLER_H
