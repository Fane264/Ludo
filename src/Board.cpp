#include "C:\Users\Fane\Documents\GitHub\Ludo\Include\Board.h"

Board::Board(int numPlayers, int piecesPerPlayer) {
    for (int i = 0; i < numPlayers; ++i) {
        players.emplace_back("Player " + std::to_string(i + 1), piecesPerPlayer);
    }
}

void Board::movePlayerPiece(int playerIndex, int pieceIndex, int steps) {
    players[playerIndex].movePiece(pieceIndex, steps);
}

void Board::displayBoard() const {
    for (const auto& player : players) {
        std::cout << player << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Board& board) {
    os << "Board(players=[";
    for (const auto& player : board.players) {
        os << player << " ";
    }
    os << "])";
    return os;
}

