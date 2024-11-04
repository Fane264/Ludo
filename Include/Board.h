
#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Player.h"

class Board {
    std::vector<Player> players;

public:
    Board(int numPlayers, int piecesPerPlayer);
    void movePlayerPiece(int playerIndex, int pieceIndex, int steps);
    void displayBoard() const;

    friend std::ostream& operator<<(std::ostream& os, const Board& board);
}; // declara board cu o lista de jucatori si piese
#endif //BOARD_H
