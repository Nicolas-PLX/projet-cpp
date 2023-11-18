#include "../../header/Piece.hpp"

using namespace std;


Piece::Piece(char s){
    symbole = s;
}

char Piece::getSymbole() const{
    return symbole;
}

ostream& operator<<(ostream &out, const Piece& piece){
    out << piece.getSymbole();
    return out;
}
