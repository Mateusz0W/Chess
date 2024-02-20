#pragma once

#include "Move.h"
#include"SFML/Graphics.hpp"
#include<string>
#include<array>

enum Piece{
    Empty,
    Pawn,
    Knight,
    Bishop,
    Rook,
    Queen,
    King,
};
enum Colors{
    Black=-1,
    White=1,
};

class ChessBoard
{
    private:
        int Board[8][8]{
            {Black*Rook,Black*Knight,Black*Bishop,Black*Queen,Black*King,Black*Bishop,Black*Knight,Black*Rook},
            {Black*Pawn,Black*Pawn,Black*Pawn,Black*Pawn,Black*Pawn,Black*Pawn,Black*Pawn,Black*Pawn,},
            {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,},
            {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,},
            {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,},
            {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,},
            {White*Pawn,White*Pawn,White*Pawn,White*Pawn,White*Pawn,White*Pawn,White*Pawn,White*Pawn,},
            {White*Rook,White*Knight,White*Bishop,White*Queen,White*King,White*Bishop,White*Knight,White*Rook},
        };
        bool en_passant_black[8];// to delete ? ->
        bool en_passant_white[8];
        bool castle_black[2];
        bool castle_white[2];//<-
        std::array<std::string,6> Pieces={"pawn","knight","bishop","rook","queen","king"};
        std::array<sf::Sprite,32> SpritesArray;
    public:
        void drawChessBoard(sf::RenderWindow& window);
        void displayPiece(sf::RenderWindow& window,std::string Name,int index);
        ChessBoard();
        friend class Move;
};