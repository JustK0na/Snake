//
// Created by Admin on 08.05.2023.
//

#ifndef SNAKE_CONTROLLER_H
#define SNAKE_CONTROLLER_H

#define FRAMERATE 15
#define WIELNAPOLE 30
#define SIZE 25

#include "Board.h"
#include "Snake.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <cmath>


class Controller {


    Board &b;
    SnakeBody &s;
    int time;
public:
    Controller(Board &board, SnakeBody &snake);
    void control(sf::RenderWindow &win);
    void movementChange(sf::Event &event);
    void movement();
    void addPoint();
    void spawnApple();
    bool checkCollision() const;
    void clickAnyButton();


};


#endif //SNAKE_CONTROLLER_H
