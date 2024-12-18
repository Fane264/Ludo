#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <memory>
#include <iostream>

/**
 * @brief Clasa abstractă pentru toate entitățile din joc.
 */
class GameEntity {
public:
 virtual ~GameEntity() = default; // destructor virtual

 /**
  * @brief Afișează informațiile despre entitate.
  */
 virtual void displayInfo() const = 0; // afiseaza informatiile despre entitate

 /**
  * @brief Creează o copie a obiectului.
  * @return Un pointer inteligent la o copie a obiectului.
  */
 virtual std::unique_ptr<GameEntity> clone() const = 0; // cloneaza obiectul
};

#endif
