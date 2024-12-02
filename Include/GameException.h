#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <stdexcept>
#include <string>

/**
 * @brief Clasa de bază pentru excepțiile jocului.
 */
class GameException : public std::exception {
protected:
    std::string message;

public:
    explicit GameException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

#endif
