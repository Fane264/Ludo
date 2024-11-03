
#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Piece.h"

class Player {
    std::vector<Piece> pieces;
    std::string name;

public:
    Player(const std::string& playerName, int numPieces);

    const std::string& getName() const;
    Piece& getPiece(int index);
    void movePiece(int pieceIndex, int steps);

    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};

#endif //PLAYER_H
