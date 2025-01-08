#include "C:/Users/Fane/Documents/GitHub/Ludo/Include/GameManager.h"
#include <random>
#include <string>
#include <iostream>

GameManager& GameManager::getInstance() {
    static GameManager instance;
    return instance;
}

void GameManager::startGame() {
    std::cout << "=== Welcome to Ludo! ===" << std::endl;

    int numPlayers = 2; // Exemplu: numărul de jucători
    int piecesPerPlayer = 4; // Exemplu: numărul de piese pe jucător

    board = std::make_unique<Board>(numPlayers, piecesPerPlayer);
    playerNames = {"Player 1", "Player 2"};
    currentPlayer = 0;

    while (!board->checkGameOver()) {
        std::cout << "\n=== Current Board State ===" << std::endl;
        board->displayBoard();

        std::cout << playerNames[currentPlayer] << ", type 'Roll' to roll the dice: ";
        std::string input;
        std::cin >> input;

        if (input != "Roll") {
            std::cout << "Invalid command. Please type 'Roll' to continue.\n";
            continue;
        }

        // Simulăm aruncarea zarului cu șanse mai mari pentru 6
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::discrete_distribution<> dist({1, 1, 1, 1, 1, 3}); // Probabilități mai mari pentru 6
        int dice = dist(gen) + 1; // Distribuția returnează valori de la 0 la 5, deci adăugăm 1

        std::cout << "You rolled a " << dice << "!" << std::endl;

        // Alege piesa de mutat
        std::cout << "Choose a piece to move (0-" << piecesPerPlayer - 1 << "): ";
        int pieceId;
        std::cin >> pieceId;

        if (!board->movePiece(currentPlayer, pieceId, dice)) {
            std::cout << "Invalid move. Try again!" << std::endl;
            continue; // Rămâne același jucător
        }

        // Dacă zarul NU este 6, trece la următorul jucător
        if (dice != 6) {
            currentPlayer = (currentPlayer + 1) % numPlayers;
        }
    }

    std::cout << "=== Game Over! ===" << std::endl;
}
