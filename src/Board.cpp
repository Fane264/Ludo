#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/Board.h"
#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/Exceptions.h"

Board::Board(int players) : numPlayers(players), playerPieces(players, std::vector<Piece>(4)) {} // initializeaza tabla cu cate 4 piese pentru fiecare

void Board::displayBoard() const {
    std::cout << "Current Board State:\n";
    for (int player = 0; player < numPlayers; ++player) {
        std::cout << "Player " << player + 1 << ": ";
        for (const auto& piece : playerPieces[player]) {
            std::cout << piece.getPosition() << " "; // afiseaza pozitia piesei
        }
        std::cout << std::endl;
    }
}

bool Board::movePiece(int playerId, int pieceId, int steps) {
    if (playerId < 0 || playerId >= numPlayers || pieceId < 0 || pieceId >= 4) {
        throw InvalidMoveException(); // verifica daca sunt valide, iar daca nu sunt arunca exceptia
    }
    Piece& piece = playerPieces[playerId][pieceId];
    if (piece.canMove(steps)) {
        piece.move(steps);
        return true; // face mutarea efectiva a piesei
    }

    std::cerr << "Invalid move! Player " << playerId + 1
              << " tried to move piece " << pieceId
              << " by " << steps << " steps.\n";
    throw InvalidMoveException();  // daca nu e valida, scrie detaliile despre eroare
    return false; // Evită warning-ul
}