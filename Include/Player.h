#ifndef PLAYER_H
#define PLAYER_H

#include "GameEntity.h"
#include <string>
#include <memory>

/**
 * @class Player
 * @brief Clasa pentru un jucător din joc.
 */
class Player : public GameEntity {
private:
    std::string name; ///< Numele jucătorului
    int score;        ///< Scorul jucătorului

public:
    /**
     * @brief Constructor pentru a inițializa un jucător.
     * @param playerName Numele jucătorului.
     * @param playerScore Scorul inițial al jucătorului.
     */
    Player(std::string playerName, int playerScore);

    /**
     * @brief Crește scorul jucătorului.
     */
    void incrementScore();

    /**
     * @brief Obține numele jucătorului.
     * @return Numele jucătorului.
     */
    [[nodiscard]] std::string getName() const;

    /**
     * @brief Obține scorul jucătorului.
     * @return Scorul jucătorului.
     */
    [[nodiscard]] int getScore() const;

    /**
     * @brief Afișează informațiile despre jucător.
     */
    void displayInfo() const override;

    /**
     * @brief Creează o copie a jucătorului.
     * @return Un pointer unic către o copie a jucătorului.
     */
    [[nodiscard]] std::unique_ptr<GameEntity> clone() const override;
};

#endif // PLAYER_H
