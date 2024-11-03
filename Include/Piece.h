
#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <utility>
class Piece {
    int position;
    const int startPosition;

public:
    Piece(int startPos);

    Piece(const Piece& other);

    Piece& operator=(const Piece& other);

    ~Piece();

    int getPosition() const;
    void move(int steps);
    bool isAtStart() const;

    friend std::ostream& operator<<(std::ostream& os, const Piece& piece);
};

#endif //PIECE_H
