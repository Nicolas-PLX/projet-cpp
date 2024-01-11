#include "../../header/Piece.hpp"

using namespace std;


Piece::Piece(char s, Joueur *j, bool e, string t) : symbole(s), proprietaire(j), espion(e), type(t){}

Piece::Piece(char s, Joueur *j, bool esp) :symbole(s),proprietaire(j), espion(esp){}
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

bool Piece::estEspion() const{
    return espion;
}