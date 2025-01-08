#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/Player.h"
#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/Board.h"
#include <iostream>
#include <random>
#include <string>
#include <vector>

/**
 * @brief Funcție pentru a simula aruncarea zarului.
 * @return Valoarea zarului, cu șanse mai mari pentru 6.
 */
int rollDice() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::discrete_distribution<> dist({1, 1, 1, 1, 1, 3}); // Șanse mai mari pentru 6
    return dist(gen) + 1;
}

int main() {
    try {
        std::cout << "=== Welcome to Ludo! ===" << std::endl;

        int numPlayers = 2; // Număr de jucători
        int piecesPerPlayer = 4; // Număr de piese pe jucător
        Board board(numPlayers, piecesPerPlayer);

        std::vector<std::string> playerNames = {"Player 1", "Player 2"};
        std::vector<int> scores(numPlayers, 0);

        int currentPlayer = 0; // Jucătorul curent
        while (!board.checkGameOver()) {
            std::cout << "\n=== Current Board State ===" << std::endl;
            board.displayBoard();

            std::cout << playerNames[currentPlayer] << ", type 'Roll' to roll the dice: ";
            std::string input;
            std::cin >> input;

            if (input != "Roll") {
                std::cout << "Invalid command. Please type 'Roll' to continue.\n";
                continue;
            }

            int diceRoll = rollDice();
            std::cout << "You rolled a " << diceRoll << "!" << std::endl;

            if (diceRoll == 6) {
                std::cout << "You get another turn after this move!" << std::endl;
            }

            // Alege piesa de mutat
            std::cout << "Choose a piece to move (0-" << piecesPerPlayer - 1 << "): ";
            int pieceId;
            std::cin >> pieceId;

            if (!board.movePiece(currentPlayer, pieceId, diceRoll)) {
                std::cout << "Invalid move. Try again!" << std::endl;
                continue; // Rămâne același jucător
            }

            // Dacă zarul NU este 6, trece la următorul jucător
            if (diceRoll != 6) {
                currentPlayer =(currentPlayer + 1) % numPlayers;
            }
        }

        std::cout << "=== Game Over! ===" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}