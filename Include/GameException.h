#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <stdexcept>
#include <string>

/**
 * @brief Clasa de bază pentru excepțiile jocului.
 */
class GameException : public std::exception {
protected:
    std::string message; ///< Mesajul de eroare.

public:
    /**
     * @brief Constructor care inițializează mesajul de eroare.
     * @param msg Mesajul de eroare.
     */
    explicit GameException(std::string msg) noexcept : message(std::move(msg)) {}

    /**
     * @brief Returnează mesajul de eroare.
     * @return Mesajul de eroare.
     */
    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // GAMEEXCEPTION_H
