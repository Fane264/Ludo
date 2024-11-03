
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
};
#endif //BOARD_H
