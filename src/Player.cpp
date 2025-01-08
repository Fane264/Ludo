#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/Player.h"
#include <iostream>
#include <memory>
Player::Player(std::string playerName, int playerScore)
    : name(std::move(playerName)), score(playerScore) {}

void Player::incrementScore() {
    ++score;
}

[[nodiscard]] std::string Player::getName() const {
    return name;
}

[[nodiscard]] int Player::getScore() const {
    return score;
}

void Player::displayInfo() const {
    std::cout << "Player: " << name << ", Score: " << score << std::endl;
}

[[nodiscard]] std::unique_ptr<GameEntity> Player::clone() const {
    return std::make_unique<Player>(*this);
}