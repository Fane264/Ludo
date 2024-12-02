#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "GameException.h"

/**
 * @brief Excepție pentru mutări invalide.
 */
class InvalidMoveException : public GameException {
public:
    InvalidMoveException() : GameException("Invalid move!") {}
};

/**
 * @brief Excepție pentru jucători.
 */
class PlayerException : public GameException {
public:
    PlayerException() : GameException("Player-related error!") {}
};

/**
 * @brief Excepție generală pentru joc.
 */
class GeneralGameException : public GameException {
public:
    GeneralGameException() : GameException("General game error!") {}
};

#endif
