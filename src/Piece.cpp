#include "C:\Users\Fane\Documents\GitHub\Ludo\Include\Piece.h"

Piece::Piece(int startPos) : position(startPos), startPosition(startPos) {}

Piece::Piece(const Piece& other) : position(other.position), startPosition(other.startPosition) {}

Piece& Piece::operator=(const Piece& other) {
    if (this != &other) {
        position = other.position;
    }
    return *this;
}

Piece::~Piece() {}

int Piece::getPosition() const {
    return position;
}

void Piece::move(int steps) {
    position += steps;
}

bool Piece::isAtStart() const {
    return position == startPosition;
}

std::ostream& operator<<(std::ostream& os, const Piece& piece) {
    os << "Piece(position=" << piece.position << ")";
    return os;
}

