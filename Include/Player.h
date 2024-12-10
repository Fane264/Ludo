#ifndef PLAYER_H
#define PLAYER_H

#include "GameEntity.h"
#include <string>

/**
 * @brief Clasa pentru un jucător în joc.
 */
class Player : public GameEntity {
private:
    std::string name; // nume jucator
    int score; // scorul jucatorului

public:
    Player(const std::string& playerName, int playerScore); // constructor
    void displayInfo() const override; // afiseaza informatiile despre jucaotr
    std::unique_ptr<GameEntity> clone() const override; // realizeaza o copie a jucatorului
};

#endif
