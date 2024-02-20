#include "ChessBoard.h"
#include "Move.h"
#include<iostream>

int main()
{
    ChessBoard board;
    Move move;

    sf::RenderWindow window(sf::VideoMode(1200, 1200), "Chess");
        while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
             
        move.PieceMovement(window,board);
        
        window.clear();
        board.drawChessBoard(window);
        window.display();
    }
    return 0;
}