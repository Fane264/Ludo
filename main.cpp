#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/Player.h"
#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/Piece.h"
#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/SpecialPiece.h"
#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/Board.h"
#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/Exceptions.h"
#include <iostream>

int main() {
    try {
        // Inițializare jucători
        Player player1("Alice", 0);
        Player player2("Bob", 0);

        // Afișarea informațiilor despre jucători
        std::cout << "=== Players ===" << std::endl;
        player1.displayInfo();
        player2.displayInfo();

        // Crearea tablei de joc pentru 2 jucători
        Board board(2);

        std::cout << "\n=== Initial Board ===" << std::endl;
        board.displayBoard();

        // Mutarea pieselor și demonstrarea funcționalității
        std::cout << "\n=== Gameplay ===" << std::endl;

        std::cout << "Player 1 rolls a 6 and moves piece 0...\n";
        try {
            board.movePiece(0, 0, 6); // Jucătorul 1 mută piesa 0
        } catch (const InvalidMoveException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        board.displayBoard();

        std::cout << "Player 2 rolls a 4 and tries to move piece 0...\n";
        try {
            board.movePiece(1, 0, 4); // Jucătorul 2 încearcă să mute piesa 0
        } catch (const InvalidMoveException& e) {
            std::cerr << "Error: " << e.what() << std::endl; // Mutare invalidă
        }
        board.displayBoard();

        std::cout << "Player 1 rolls a 3 and moves piece 0 again...\n";
        try {
            board.movePiece(0, 0, 3); // Jucătorul 1 mută din nou piesa 0
        } catch (const InvalidMoveException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        board.displayBoard();

        std::cout << "Player 2 rolls a 6 and moves piece 0...\n";
        try {
            board.movePiece(1, 0, 6); // Jucătorul 2 mută piesa 0
        } catch (const InvalidMoveException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        board.displayBoard();

        // Demonstrăm o piesă specială
        SpecialPiece specialPiece(0, true);
        std::cout << "\n=== Special Piece ===" << std::endl;
        specialPiece.displayInfo();

        std::cout << "\nCloning special piece...\n";
        auto clonedPiece = specialPiece.clone(); // Clonare piesă
        clonedPiece->displayInfo();

    } catch (const GameException& e) {
        std::cerr << "Game error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\nGame Over!" << std::endl;
    return 0;
}