
#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Piece.h"

class Player {
    std::vector<Piece> pieces;
    std::string name; // vectori pentru piese si numele jucatorului

public:
    Player(const std::string& playerName, int numPieces); // initializez playerii si numarul de piese

    const std::string& getName() const; // returnez numele jucatorului
    Piece& getPiece(int index); // returnez referinta la piesa
    void movePiece(int pieceIndex, int steps); // muta piesa cu numarul de pasi specificat

    friend std::ostream& operator<<(std::ostream& os, const Player& player); // suprascrie "<<" pentru afisarea jucatorului
};

#endif //PLAYER_H
