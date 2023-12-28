#pragma once

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


struct Board_state
{
    int Board[8][8]{
        {Black*Rook,Black*Knight,Black*Bishop,Black*Queen,Black*King,Black*Bishop,Black*Knight,Black*Rook},
        {Black*Pawn,Black*Pawn,Black*Pawn,Black*Pawn,Black*Pawn,Black*Pawn,Black*Pawn,Black*Pawn,},
        {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,},
        {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,},
        {White*Pawn,White*Pawn,White*Pawn,White*Pawn,White*Pawn,White*Pawn,White*Pawn,White*Pawn,},
        {White*Rook,White*Knight,White*Bishop,White*Queen,White*King,White*Bishop,White*Knight,White*Rook},
    };
    bool en_passant_black[8];
    bool en_passant_white[8];
    bool castle_black[2];
    bool castle_white[2];

};



