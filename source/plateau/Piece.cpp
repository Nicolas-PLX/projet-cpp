#include "../../header/Piece.hpp"

using namespace std;


Piece::Piece(char s, Joueur *j, bool e, string t) : symbole(s), proprietaire(j), espion(e), type(t){
    /*
    proprietaire = j;
    symbole = s;
    type = t;*/
}

Piece::Piece(char s, Joueur *j, bool espion) :symbole(s),proprietaire(j), espion(espion){cout << "j'utilise celui là" << endl; type = "";}


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
/*
Couleur Piece::getCouleur() const{
    return couleur;
}
*/
/*
ostream& operator<<(ostream &out, const Piece& pion){
    out << pion.getCouleur() <<" Espion : "<< pion.estEspion();
    return out;
}
*/