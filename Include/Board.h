#ifndef BOARD_H
#define BOARD_H

#include "GameException.h"
#include "Piece.h"
#include <vector>

/**
 * @brief Clasa care reprezintă tabla de joc pentru Ludo.
 */
class Board {
private:
 int numPlayers; ///< Numărul de jucători.
 std::vector<std::vector<Piece>> playerPieces; ///< Matricea pieselor fiecărui jucător.

 /**
  * @brief Verifică capturarea unei piese.
  * @param playerId ID-ul jucătorului curent.
  * @param movedPiece Referința către piesa mutată.
  */
 void checkCapture(int playerId, const Piece& movedPiece);

public:
 /**
  * @brief Constructor pentru clasa Board.
  * @param players Numărul de jucători.
  * @param piecesPerPlayer Numărul de piese per jucător.
  */
 Board(int players, int piecesPerPlayer);

 /**
  * @brief Afișează starea curentă a tablei.
  */
 void displayBoard() const;

 /**
  * @brief Mută o piesă a jucătorului.
  * @param playerId ID-ul jucătorului.
  * @param pieceId ID-ul piesei de mutat.
  * @param steps Numărul de pași de mutat.
  * @return true dacă mutarea a avut loc, false altfel.
  * @throw InvalidMoveException dacă mutarea nu este validă.
  */
 bool movePiece(int playerId, int pieceId, int steps);

 /**
  * @brief Verifică dacă jocul s-a terminat.
  * @return true dacă un jucător a câștigat, false altfel.
  */
 bool checkGameOver() const;
};

#endif // BOARD_H
