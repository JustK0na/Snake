//
// Created by Admin on 08.05.2023.
//

#ifndef SNAKE_VIEW_H
#define SNAKE_VIEW_H

#include "Board.h"
#include "Snake.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/VideoMode.hpp>

#include "iostream"
class View {
    Board &b;
    Snake &s;

public:
    View(Board &b, Snake &s);
    void present(sf::RenderWindow &window) const;
    void drawBackground(sf::RenderWindow &window) const;
    void drawSnake(sf::RenderWindow &window) const;
};


#endif //SNAKE_VIEW_H
