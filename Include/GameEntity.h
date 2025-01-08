#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <memory>


/**
 * @brief Clasa abstractă pentru toate entitățile din joc.
 */
class GameEntity {
public:
 GameEntity() = default;
 virtual ~GameEntity() = default;

 /**
  * @brief Afișează informațiile despre entitate.
  */
 virtual void displayInfo() const = 0;

 /**
  * @brief Creează o copie a obiectului.
  * @return Un pointer inteligent la o copie a obiectului.
  */
 [[nodiscard]]  virtual std::unique_ptr<GameEntity> clone() const = 0;
};

#endif // GAMEENTITY_H
