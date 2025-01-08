#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/Piece.h"
#include <iostream>

Piece::Piece(int startPosition) : position(startPosition), isInBase(true) {}

void Piece::move(int steps) {
    if (isInBase && steps == 6) {
        isInBase = false;  // Scoatem piesa din bază
        position = 1;      // Prima poziție pe tablă
    } else if (!isInBase) {
        position += steps; // Mutăm piesa pe tablă
    }
}

bool Piece::canMove(int steps) const {
    if (isInBase) {
        return steps == 6; // Piesa poate fi scoasă doar dacă zarul este 6
    }
    return (position + steps <= 57); // Piesa se poate muta doar dacă nu depășește tabla
}

void Piece::reset() {
    position = 0;
    isInBase = true;
}

int Piece::getPosition() const {
    return position;
}

void Piece::displayInfo() const {
    std::cout << "Piece at position: " << position << (isInBase ? " (In Base)" : "") << std::endl;
}