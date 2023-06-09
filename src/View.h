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

#define MARGINES 20
#define  GUI 200

enum Texts {
    NOTHINGTEXT,
    CLASSICTEXT,
    CUBETEXT,
    EXITTEXT
};


class View {
    std::vector<Board> &b;
    SnakeBody &s;
    Texts highlight;

public:
    View(std::vector<Board> &b, SnakeBody &s);
    void present(sf::RenderWindow &window) const;
    void drawBackground(sf::RenderWindow &window) const;
    void drawSnake(sf::RenderWindow &window) const;
    void drawApples(sf::RenderWindow &window) const;
    void writeText(sf::RenderWindow &) const;
    void Highlight(Texts);
};


#endif //SNAKE_VIEW_H
