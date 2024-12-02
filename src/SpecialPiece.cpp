#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/SpecialPiece.h"

SpecialPiece::SpecialPiece(int startPosition, bool power)
    : Piece(startPosition), hasPower(power) {}

void SpecialPiece::displayInfo() const {
    Piece::displayInfo();
    std::cout << "Special ability: " << (hasPower ? "Enabled" : "Disabled") << std::endl;
}

std::unique_ptr<GameEntity> SpecialPiece::clone() const {
    return std::make_unique<SpecialPiece>(*this);
}
