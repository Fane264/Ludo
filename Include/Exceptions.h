#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "GameException.h"

/**
 * @brief Excepție pentru mutări invalide.
 */
class InvalidMoveException : public GameException { // clasa pentru mutarile invalide
public:
    InvalidMoveException() : GameException("Invalid move!") {} // definesc o exceptie pentru mutarile invalide
};

/**
 * @brief Excepție pentru jucători.
 */
class PlayerException : public GameException { // clasa pentru exceptiile legate de jucatori
public:
    PlayerException() : GameException("Player-related error!") {} // definesc o exceptie pentru erorile legate de jucator
};

/**
 * @brief Excepție generală pentru joc.
 */
class GeneralGameException : public GameException { // clasa pentru erorile generale
public:
    GeneralGameException() : GameException("General game error!") {} // definesc o exceptie generala
};

#endif
