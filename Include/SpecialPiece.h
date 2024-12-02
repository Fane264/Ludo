#ifndef SPECIALPIECE_H
#define SPECIALPIECE_H

#include "Piece.h"

/**
 * @brief Clasa pentru o piesă specială cu abilități suplimentare.
 */
class SpecialPiece : public Piece {
private:
    bool hasPower;

public:
    SpecialPiece(int startPosition = 0, bool power = false);
    void displayInfo() const override;
    std::unique_ptr<GameEntity> clone() const override;
};

#endif
