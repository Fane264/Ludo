#include "C:\Users\Fane\Documents\GitHub\Ludo\Include\Piece.h" // nu stiu de ce nu merge sa dau direct Piece.h sau Include/Piece.h ????

Piece::Piece(int startPos) : position(startPos), startPosition(startPos) {} // initializez pozitiile de start

Piece::Piece(const Piece& other) : position(other.position), startPosition(other.startPosition) {} // acelasi lucru ca mai sus doar ca iau ce se afla in other

Piece& Piece::operator=(const Piece& other) {
    if (this != &other) {
        position = other.position;
    }
    return *this;
} // operatorul de atribuire verifica daca obiectul este diferit de cel curent

Piece::~Piece() {} // destructorul

int Piece::getPosition() const {
    return position;
} // returnez pozitia initiala

void Piece::move(int steps) {
    position += steps;
} // mut cu x pozitii date

bool Piece::isAtStart() const {
    return position == startPosition;
} // verific daca e la start

std::ostream& operator<<(std::ostream& os, const Piece& piece) {
    os << "Piece(position=" << piece.position << ")";
    return os;
} // suprascriu pentru a afisa mai frumos

