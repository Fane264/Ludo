#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <vector>

/**
 * @brief Clasa pentru gestionarea tablei de joc.
 */
class Board {
private:
    int numPlayers;
    std::vector<std::vector<Piece>> playerPieces;

public:
    Board(int players);
    void displayBoard() const;
    bool movePiece(int playerId, int pieceId, int steps);
};

#endif
