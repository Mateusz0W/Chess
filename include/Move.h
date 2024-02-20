#pragma once

#include"ChessBoard.h"
#include"SFML/Graphics.hpp"

class ChessBoard;

class Move{
    public:
        void PieceMovement(sf::RenderWindow& window,ChessBoard& board);
};