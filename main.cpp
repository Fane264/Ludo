#include <iostream>
#include "Include/Board.h"

int main() {
    // Creare board cu 2 jucători, fiecare cu 4 piese
    Board board(2, 4);

    // Mutare piese
    board.movePlayerPiece(0, 0, 3);  // Mutăm prima piesă a primului jucător cu 3 poziții
    board.movePlayerPiece(1, 2, 5);  // Mutăm a treia piesă a celui de-al doilea jucător cu 5 poziții

    // Afișare board
    board.displayBoard();

    return 0;
}
