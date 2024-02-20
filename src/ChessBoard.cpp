#include "ChessBoard.h"
#include <iostream>

using namespace std;

void ChessBoard::drawChessBoard(sf::RenderWindow& window){
     //drawing chessboard
     sf::Texture texture;
     if (!texture.loadFromFile("../assets/Chessboard.png"))
     {
          std::cerr << "Failed to load image BOARD." << std::endl;
          exit(EXIT_FAILURE);
     }        
     sf::Sprite sprite;
     sprite.scale(sf::Vector2f(3.f, 3.f));
     sprite.setTexture(texture);
     window.draw(sprite);
     //drawing pieces
     string NameOfPiece;
     int index = 0;
     for(int i=0;i<8;i++){
          for(int j=0;j<8;j++){
               if(Board[i][j]!=0){
                    if(Board[i][j]>0) //if piece is White
                         NameOfPiece="W"+Pieces[Board[i][j]-1]+".png"; 
                    else
                         NameOfPiece="B"+Pieces[-Board[i][j]-1]+".png"; 
                    displayPiece(window,NameOfPiece,index);
                    index++;
               }    
          } 
     }
}
void ChessBoard::displayPiece(sf::RenderWindow& window,string Name,int index){
     string path="../assets/"+Name;
     sf::Texture texture;
     texture.setSmooth(true);
     if (!texture.loadFromFile(path))
     {
          std::cerr << "Failed to load image PIECE." << std::endl;
          exit(EXIT_FAILURE);
     }      
     SpritesArray[index].setScale(sf::Vector2f(0.5f, 0.5f));
     SpritesArray[index].setTexture(texture);
     window.draw(SpritesArray[index]);
}
ChessBoard::ChessBoard(){
     // Seting starting positions of pieces
     float x=0.f , y=0.f;
     for(int i=0;i<32;i++){
          if(i % 8 == 0 && i != 0){
               x=0.0f;
               y+=150.f;
          }
          if(i==16)
               y=900.f;
          SpritesArray[i].setPosition(sf::Vector2f(x,y));//+150.f   
          x+=150.f;
     }
}