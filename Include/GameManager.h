#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Board.h"
#include <iostream>
#include <memory>
#include <vector>

/**
 * @class GameManager
 * @brief Clasa responsabilă pentru gestionarea jocului Ludo.
 */
class GameManager {
private:
 std::unique_ptr<Board> board; ///< Pointer către tabla de joc
 std::vector<std::string> playerNames; ///< Numele jucătorilor
 int currentPlayer = 0; ///< Jucătorul curent (inițializat la 0)

 // Constructor privat pentru Singleton
 GameManager() : board(nullptr), playerNames{}, currentPlayer(0) {}

public:
 GameManager(const GameManager&) = delete;
 GameManager& operator=(const GameManager&) = delete;

 /**
  * @brief Returnează instanța singleton a clasei.
  * @return Instanța GameManager.
  */
 static GameManager& getInstance();

 /**
  * @brief Pornește jocul.
  */
 void startGame();
};

#endif // GAMEMANAGER_H
