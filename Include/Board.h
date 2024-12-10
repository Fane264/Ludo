#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <vector>

/**
 * @brief Clasa pentru gestionarea tablei de joc.
 */
class Board {
private:
    int numPlayers; // variabila pentru numarul de jucatori
    std::vector<std::vector<Piece>> playerPieces; // matrice pentru stocarea pieselor fiecarui jucator

public:
    Board(int players); // constructorul clasei care initializeaza cu un numar de jucatori
    void displayBoard() const; // afiseaza starea curenta a tablei
    bool movePiece(int playerId, int pieceId, int steps); // muta o piesa pe tabla si verifica validitatea acesteia
};

#endif
