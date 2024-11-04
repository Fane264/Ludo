#include <iostream>
#include "Include/Board.h"

int main() {
    Board board(2,4);
    std::cout <<"Starea initiala a tablei de joc"<< std::endl;
    board.displayBoard();

    std::cout <<"Mut piesa 0 a primului jucator cu 3 pasi"<< std::endl;
    board.movePlayerPiece(0, 0, 3);
    board.displayBoard();

    std::cout <<"Mut piesa 1 a celui de-al doilea jucator cu 5 pasi"<< std::endl;
    board.movePlayerPiece(1, 2, 5);
    board.displayBoard();

    std::cout <<"Mut piesa 0 a primului jucator inapoi la start"<< std::endl;
    board.movePlayerPiece(0, 0, -3);
    board.displayBoard();


    //Testez daca toate piesele se pot muta simultan
    board.movePlayerPiece(1,0,2);
    board.movePlayerPiece(1,1,3);
    board.movePlayerPiece(1,2,4);
    board.movePlayerPiece(1,3,7);
    board.displayBoard();

    std::cout <<"Starea finala a tablei de joc";
    board.displayBoard();

    return 0;
}
