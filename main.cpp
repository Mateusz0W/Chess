#include "Board_representation.h"

int main()
{
    ChessBoard board;

    sf::RenderWindow window(sf::VideoMode(1200, 1200), "Chess");
        while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        board.drawChessBoard(window);
        window.display();
    }



    return 0;
}