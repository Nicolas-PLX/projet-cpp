#include "../../header/Case.hpp"

Case::Case(){
    piece = nullptr;
}

Case::Case(Piece *p){
    piece = p;
}

Piece * Case::getPiece() const{
    return this->piece;
}

void Case::setPiece(Piece *p){
    piece = p;
}

std::ostream& operator<<(std::ostream &out, const Case& c){
    Piece *p = c.getPiece();
    if (!p){
        out << " ";
    } else {
        out << *p;
    }

    return out;
}
