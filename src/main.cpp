#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>

#include "Board.h"
int main() {

    Board b(500, 700);
    sf::RenderWindow win(sf::VideoMode(b.getWidth(), b.getHeight()), "Snake");
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Width: " <<b.getWidth()<<"\tHeight: "<<b.getHeight();

    while (win.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (win.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                win.close();
        }

    }

    return 0;
    return 0;

}


