#include "Board_representation.h"
#include <iostream>

void ChessBoard::drawChessBoard(sf::RenderWindow& window){
     sf::Texture texture;
     if (!texture.loadFromFile("../assets/Chessboard.png"))
     {
          std::cerr << "Failed to load image." << std::endl;
          exit(EXIT_FAILURE);
     }        
     sf::Sprite sprite;
     sprite.scale(sf::Vector2f(3.f, 3.f));
     sprite.setTexture(texture);
     window.draw(sprite);

}