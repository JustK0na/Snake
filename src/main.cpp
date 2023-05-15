#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>
#include "Board.h"
#include "View.h"
#include "Controller.h"

#define SIZE 25
int main() {

    srand(time(NULL));

    Board b(SIZE, SIZE);

    SnakeBody s(SIZE/2,SIZE/2);

    View scenery(b,s);

    Controller controller(b, s);



    sf::RenderWindow win(sf::VideoMode(2*MARGINES+b.getCols()*WIELPOLE, b.getRows()*WIELPOLE+MARGINES+GUI), "Snake");
    win.setFramerateLimit(FRAMERATE);



    while (win.isOpen())
    {
        controller.control(win);
        scenery.present(win);
    }

    return 0;
    return 0;

}


