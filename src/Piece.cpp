#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/Piece.h"
#include <iostream>


Piece::Piece(int startPosition) : position(startPosition), isInBase(true) {} // initializeaza pozitia in baza

void Piece::move(int steps) {
    if (isInBase && steps == 6) {
        isInBase = false; // piesa iese din baza
        position = 1; // prima poziție pe tabla
    } else if (!isInBase) {
        position += steps; // actualizeaza poziția
    }
}

bool Piece::canMove(int steps) const {
    // Reguli de validare:
    // 1. Daca piesa este în baza, mutarea este valida doar dacă zarul arata 6
    // 2. Daca piesa este deja pe tabla, mutarea este valida doar daca nu depaseste limita (poziția 57)
    return isInBase ? steps == 6 : (position + steps <= 57);
}

void Piece::reset() {
    position = 0; // reseteaza la baza
    isInBase = true; // marcheaza piesa ca fiind în baza
}

int Piece::getPosition() const {
    return position; // returnează poziția curenta
}

void Piece::displayInfo() const {
    std::cout << "Piece at position: " << position << (isInBase ? " (In Base)" : "") << std::endl;
}

std::unique_ptr<GameEntity> Piece::clone() const {
    return std::make_unique<Piece>(*this); // Returneaza o copie a piesei
}