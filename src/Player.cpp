#include "C:\Users\Fane\Documents\GitHub\Ludo\Include\Player.h"

Player::Player(const std::string& playerName, int numPieces) : name(playerName) {
    for (int i = 0; i < numPieces; ++i) {
        pieces.emplace_back(0);  // fiecare piesă începe la poziția 0
    }
} // constructorul initializeaza numele si creeaza x obiecte la pozitia de start

const std::string& Player::getName() const {
    return name;
}

Piece& Player::getPiece(int index) {
    return pieces[index];
}

void Player::movePiece(int pieceIndex, int steps) {
    pieces[pieceIndex].move(steps);
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Player(name=" << player.name << ", pieces=[";
    for (const auto& piece : player.pieces) {
        os << piece << " ";
    }
    os << "])";
    return os; // suprascrie "<<" pentru a afisa detalii despre jucatori
}
