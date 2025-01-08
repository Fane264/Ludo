#ifndef PIECEFACTORY_H
#define PIECEFACTORY_H

#include "Piece.h"
#include <memory>

enum class PieceType { Standard };

class PieceFactory {
public:
    static std::unique_ptr<Piece> createPiece(PieceType type, int startPosition = 0) {
        switch (type) {
        case PieceType::Standard:
            return std::make_unique<Piece>(startPosition);
        default:
            throw std::invalid_argument("Unknown piece type");
        }
    }
};

#endif // PIECEFACTORY_H
