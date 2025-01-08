#ifndef PIECE_H
#define PIECE_H



/**
 * @class Piece
 * @brief Reprezintă o piesă de pe tabla de joc Ludo.
 */
class Piece {
private:
 int position; ///< Poziția curentă a piesei pe tablă
 bool isInBase; ///< Indică dacă piesa se află în bază

public:
 /**
  * @brief Constructor pentru a inițializa piesa.
  * @param startPosition Poziția de start a piesei (default 0).
  */
 explicit Piece(int startPosition = 0); // Adăugat `explicit` pentru a evita conversiile implicite

 /**
  * @brief Mută piesa pe tablă.
  * @param steps Numărul de pași de mutare.
  */
 void move(int steps);

 /**
  * @brief Verifică dacă piesa poate fi mutată cu un anumit număr de pași.
  * @param steps Numărul de pași verificați.
  * @return True dacă mutarea este permisă, altfel False.
  */
 [[nodiscard]] bool canMove(int steps) const; // Marcată cu `[[nodiscard]]` pentru a indica utilizarea obligatorie a valorii returnate

 /**
  * @brief Resetează piesa la poziția inițială (bază).
  */
 void reset();

 /**
  * @brief Obține poziția curentă a piesei.
  * @return Poziția curentă a piesei.
  */
 [[nodiscard]] int getPosition() const; // Marcată cu `[[nodiscard]]`

 /**
  * @brief Afișează informații despre piesă.
  */
 void displayInfo() const;
};

#endif // PIECE_H
