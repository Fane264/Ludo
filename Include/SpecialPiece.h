#ifndef SPECIALPIECE_H
#define SPECIALPIECE_H

#include "Piece.h"

/**
 * @brief Clasa pentru o piesă specială cu abilități suplimentare.
 */
class SpecialPiece : public Piece {
private:
    bool hasPower; // indica daca piesa are o abilitate speciala

public:
    SpecialPiece(int startPosition = 0, bool power = false); // constructor
    void displayInfo() const override; // afiseaza informatii despre piesa speciala
    std::unique_ptr<GameEntity> clone() const override; // creeaza o copie
};

#endif
