#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/Player.h"
#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/Piece.h"
#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/SpecialPiece.h"
#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/Board.h"
#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/Exceptions.h"
#include <iostream>

int main() {
    try {
        Player player1("Stefan", 0);
        Player player2("Gigel", 0); // creez jucatorii


        std::cout << "=== Players ===" << std::endl;
        player1.displayInfo();
        player2.displayInfo(); // afisez informatiile despre jucatori


        Board board(2); // creez tabla pentru 2 jucatori

        std::cout << "\n=== Initial Board ===" << std::endl;
        board.displayBoard(); // afisez starea initiala a tablei


        std::cout << "\n=== Gameplay ===" << std::endl;

        std::cout << "Player 1 rolls a 6 and moves piece 0...\n";
        try {
            board.movePiece(0, 0, 6); // jucatorul 1 muta piesa 0
        } catch (const InvalidMoveException& e) {
            std::cerr << "Error: " << e.what() << std::endl; // daca nu e valida mutarea, intra pe exceptie
        }
        board.displayBoard();

        std::cout << "Player 2 rolls a 4 and tries to move piece 0...\n";
        try {
            board.movePiece(1, 0, 4);
        } catch (const InvalidMoveException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        board.displayBoard();

        std::cout << "Player 1 rolls a 3 and moves piece 0 again...\n";
        try {
            board.movePiece(0, 0, 3);
        } catch (const InvalidMoveException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        board.displayBoard();

        std::cout << "Player 2 rolls a 6 and moves piece 0...\n";
        try {
            board.movePiece(1, 0, 6);
        } catch (const InvalidMoveException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        board.displayBoard();


        SpecialPiece specialPiece(0, true); // creez piesa speciala
        std::cout << "\n=== Special Piece ===" << std::endl;
        specialPiece.displayInfo(); // ii afisez informatiile

        std::cout << "\nCloning special piece...\n";
        auto clonedPiece = specialPiece.clone(); // clonez piesa speciala
        clonedPiece->displayInfo();

    } catch (const GameException& e) {
        std::cerr << "Game error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl; // prinde exceptiile generale ale jocului si le afiseaza mesajele
    }

    std::cout << "\nGame Over!" << std::endl;
    return 0;
}