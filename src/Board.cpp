#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/Board.h"
#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/Piece.h"
#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/Exceptions.h"
#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/GameException.h"
#include <iostream>
#include <stdexcept>

Board::Board(int players, int piecesPerPlayer)
    : numPlayers(players), playerPieces(players, std::vector<Piece>(piecesPerPlayer)) {}

void Board::displayBoard() const {
    std::cout << "=== Current Board State ===" << std::endl;
    for (int player = 0; player < numPlayers; ++player) {
        std::cout << "Player " << player + 1 << ": ";
        for (const auto& piece : playerPieces[player]) {
            std::cout << piece.getPosition() << " ";
        }
        std::cout << std::endl;
    }
}

bool Board::movePiece(int playerId, int pieceId, int steps) {
    if (playerId < 0 || playerId >= numPlayers || pieceId < 0 || pieceId >= playerPieces[playerId].size()) {
        throw std::out_of_range("Invalid player or piece ID.");
    }

    Piece& piece = playerPieces[playerId][pieceId];

    // Verificăm dacă mutarea este validă
    if (!piece.canMove(steps)) {
        std::cerr << "Invalid move for piece " << pieceId << " with steps " << steps << "." << std::endl;
        return false;
    }

    // Mutăm piesa
    piece.move(steps);

    // Verificăm dacă a lovit o piesă a altui jucător
    for (int otherPlayer = 0; otherPlayer < numPlayers; ++otherPlayer) {
        if (otherPlayer != playerId) {
            for (auto& otherPiece : playerPieces[otherPlayer]) {
                if (!otherPiece.canMove(0) && otherPiece.getPosition() == piece.getPosition()) {
                    std::cout << "Player " << otherPlayer + 1 << "'s piece sent back to base!" << std::endl;
                    otherPiece.reset();
                }
            }
        }
    }

    return true;
}

bool Board::checkGameOver() const {
    for (int player = 0; player < numPlayers; ++player) {
        bool allInBase = true;
        for (const auto& piece : playerPieces[player]) {
            if (piece.getPosition() != 57) { // Poziția 57 este "casa finală"
                allInBase = false;
                break;
            }
        }
        if (allInBase) {
            std::cout << "Player " << player + 1 << " wins the game!" << std::endl;
            return true;
        }
    }
    return false;
}