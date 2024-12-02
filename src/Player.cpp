#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/Player.h"

Player::Player(const std::string& playerName, int playerScore) : name(playerName), score(playerScore) {}

void Player::displayInfo() const {
    std::cout << "Player: " << name << ", Score: " << score << std::endl;
}

std::unique_ptr<GameEntity> Player::clone() const {
    return std::make_unique<Player>(*this);
}
