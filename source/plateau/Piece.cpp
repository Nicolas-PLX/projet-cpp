#include "../../header/Piece.hpp"

using namespace std;


Piece::Piece(char s, Joueur *j, string t){
    proprietaire = j;
    symbole = s;
    type = t;
}

char Piece::getSymbole() const{
    return symbole;
}

Joueur * Piece::getProprietaire() const{
    return proprietaire;
}

string Piece::getType() const{
    return type;
}

void Piece::setType(string s) {
    type = s;
}

ostream& operator<<(ostream &out, const Piece& piece){
    out << piece.getSymbole();
    return out;
}
