#ifndef _PIECE
#define _PIECE

#include <iostream>
#include "Joueur.hpp"
#include <string>
using namespace std;

class Piece {
    private:
    Joueur * proprietaire;
    char symbole;
    string type; /* Todo : remplacer par un enum ?*/

    public:
    Piece(char s, Joueur *j, string t);
    char getSymbole() const;
    Joueur * getProprietaire() const;
    string getType() const;
    void setType(string s);
};

std::ostream& operator<<(std::ostream &os, const Piece& piece);




#endif