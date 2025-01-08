#include "C:\Users\Fane\Documents\GitHub\Ludo\Include/GameManager.h"

int main() {
    // Instanțiază și pornește jocul folosind Singleton-ul GameManager
    GameManager& manager = GameManager::getInstance();
    manager.startGame();
    return 0;
}
