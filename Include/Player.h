#ifndef PLAYER_H
#define PLAYER_H

#include "GameEntity.h"
#include <string>

/**
 * @brief Clasa pentru un jucător în joc.
 */
class Player : public GameEntity {
private:
    std::string name;
    int score;

public:
    Player(const std::string& playerName, int playerScore);
    void displayInfo() const override;
    std::unique_ptr<GameEntity> clone() const override;
};

#endif
