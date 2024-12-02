#ifndef PIECE_H
#define PIECE_H

#include "GameEntity.h"

/**
 * @brief Clasa care reprezintă o piesă de joc.
 */
class Piece : public GameEntity {
private:
    int position; ///< Poziția curentă a piesei pe tablă
    bool isInBase; ///< Indică dacă piesa se află în bază

public:
    /**
     * @brief Constructorul implicit pentru Piece.
     * @param startPosition Poziția inițială a piesei (default: 0).
     */
    Piece(int startPosition = 0);

    /**
     * @brief Mută piesa un număr de pași pe tablă.
     * @param steps Numărul de pași de mutat.
     */
    void move(int steps);

    /**
     * @brief Verifică dacă piesa poate fi mutată un anumit număr de pași.
     * @param steps Numărul de pași verificați.
     * @return true dacă mutarea este permisă, altfel false.
     */
    bool canMove(int steps) const;

    /**
     * @brief Resetează piesa la poziția inițială (bază).
     */
    void reset();

    /**
     * @brief Obține poziția curentă a piesei.
     * @return Poziția curentă a piesei.
     */
    int getPosition() const; // Adăugat pentru acces la poziție

    /**
     * @brief Afișează informațiile despre piesă.
     */
    void displayInfo() const override;

    /**
     * @brief Creează o copie a piesei.
     * @return Un pointer inteligent la o copie a obiectului curent.
     */
    std::unique_ptr<GameEntity> clone() const override;
};

#endif
