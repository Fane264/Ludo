
#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <utility>
class Piece {
    int position;
    const int startPosition;

public:
    Piece(int startPos); // construcotrul clasei care priemeste parametrul aferent pozitie de start

    Piece(const Piece& other); // constructor de copiere, pentru a crea o copie

    Piece& operator=(const Piece& other);// operator de atribuire care permite atribuirea de valori dintr un alt obiect

    ~Piece(); // destructor

    int getPosition() const; // returneaza pozitia curenta
    void move(int steps); // muta un numar specific de pozitii
    bool isAtStart() const; // verifica daca piesa se afla la pozitia initiale

    friend std::ostream& operator<<(std::ostream& os, const Piece& piece); // creat pentru a permite afisarea direct cu std::cout
};

#endif //PIECE_H
