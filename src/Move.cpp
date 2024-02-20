#include "Move.h"
#include <iostream>

using namespace std;

void Move::PieceMovement(sf::RenderWindow& window,ChessBoard& board){
    sf::Vector2i MousePosition = sf::Mouse::getPosition(window);
    static bool isMoving; // Zmienna do śledzenia, czy pionek jest aktualnie przesuwany
    static int movingPieceIndex; // Indeks przesuwanego pionka
    static sf::Vector2f offset; // Offset do śledzenia różnicy pomiędzy pozycją myszy a pozycją pionka

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (!isMoving) { // Jeśli nie ma aktywnego ruchu, sprawdzamy, czy kliknięto na pionek
            for (int i = 0; i < board.SpritesArray.size(); i++) {
                if (board.SpritesArray[i].getGlobalBounds().contains(MousePosition.x, MousePosition.y)) {
                    isMoving = true;
                    movingPieceIndex = i;
                    offset = sf::Vector2f(MousePosition) - board.SpritesArray[i].getPosition();
                    break;
                }
            }
        }
    } else {
        isMoving = false;
    }

    if (isMoving) {
        // Aktualizacja pozycji przesuwanego pionka na bieżącą pozycję myszy z uwzględnieniem offsetu
        board.SpritesArray[movingPieceIndex].setPosition(sf::Vector2f(MousePosition) - offset);
    }
}
