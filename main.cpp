#include <iostream>
#include "Include/Board.h"

int main() {
    Board board(2,4);
    std::cout <<"Starea initiala a tablei de joc"<< std::endl;
    board.displayBoard();

    std::cout <<"\nMut piesa 0 a primului jucator cu 3 pasi\n"<< std::endl;
    board.movePlayerPiece(0, 0, 3);
    board.displayBoard();

    std::cout <<"\nMut piesa 1 a celui de-al doilea jucator cu 5 pasi\n"<< std::endl;
    board.movePlayerPiece(1, 2, 5);
    board.displayBoard();

    std::cout <<"\nMut piesa 0 a primului jucator inapoi la start\n"<< std::endl;
    board.movePlayerPiece(0, 0, -3);
    board.displayBoard();

    std::cout << "\nMut piesa 4 a primului jucator cu 4 pasi\n"<< std::endl;
    board.movePlayerPiece(0, 3, 4);
    board.displayBoard();


    //Testez daca toate piesele se pot muta simultan
    board.movePlayerPiece(1,0,2);
    board.movePlayerPiece(1,1,3);
    board.movePlayerPiece(1,2,4);
    board.movePlayerPiece(1,3,7);
    board.displayBoard();

    std::cout <<"\nStarea finala a tablei de joc\n"<< std::endl;
    board.displayBoard();

    return 0;
}
