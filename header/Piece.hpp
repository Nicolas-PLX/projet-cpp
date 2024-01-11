#ifndef _PIECE
#define _PIECE

#include <iostream>
#include "Joueur.hpp"
#include <string>
using namespace std;

class Piece {
    private:
    char symbole;
    Joueur * proprietaire;
    bool espion ; //pour Incognito
    string type; 

    public:
    Piece(char s, Joueur *j, bool e, string t);
    Piece(char s, Joueur *j, bool espion);
    char getSymbole() const;
    Joueur * getProprietaire() const;
    string getType() const;
    void setType(string s);
    bool estEspion() const;
};

std::ostream& operator<<(std::ostream &os, const Piece& piece);

#endif