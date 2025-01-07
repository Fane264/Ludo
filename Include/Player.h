#ifndef PLAYER_H
#define PLAYER_H

#include "GameEntity.h"
#include <string>

/**
 * @brief Clasa pentru un jucător din joc.
 */
class Player : public GameEntity {
private:
    std::string name; // Numele jucătorului
    int score;        // Scorul jucătorului

public:
    Player(const std::string& playerName, int playerScore);

    void incrementScore();           // Crește scorul jucătorului
    std::string getName() const;     // Obține numele
    int getScore() const;            // Obține scorul

    void displayInfo() const override; // Afișează informațiile despre jucător
    std::unique_ptr<GameEntity> clone() const override; // Creează o copie
};

#endif // PLAYER_H
