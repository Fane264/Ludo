#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/Piece.h"
#include <iostream>


Piece::Piece(int startPosition) : position(startPosition), isInBase(true) {}

void Piece::move(int steps) {
    if (isInBase && steps == 6) {
        isInBase = false; // Piesa iese din bază
        position = 1; // Prima poziție pe tablă
    } else if (!isInBase) {
        position += steps; // Actualizează poziția
    }
}

bool Piece::canMove(int steps) const {
    // Reguli de validare:
    // 1. Dacă piesa este în bază, mutarea este validă doar dacă zarul arată 6.
    // 2. Dacă piesa este deja pe tablă, mutarea este validă doar dacă nu depășește limita (poziția 57).
    return isInBase ? steps == 6 : (position + steps <= 57);
}

void Piece::reset() {
    position = 0; // Resetează la bază
    isInBase = true; // Marchează piesa ca fiind în bază
}

int Piece::getPosition() const {
    return position; // Returnează poziția curentă
}

void Piece::displayInfo() const {
    std::cout << "Piece at position: " << position << (isInBase ? " (In Base)" : "") << std::endl;
}

std::unique_ptr<GameEntity> Piece::clone() const {
    return std::make_unique<Piece>(*this); // Returnează o copie a piesei
}