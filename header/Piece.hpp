#ifndef _PIECE
#define _PIECE

#include <iostream>
#include "Joueur.hpp"
#include <string>
using namespace std;

enum class Couleur{
    Noir,
    Blanc
};

class Piece {
    private:
    Joueur * proprietaire;
    char symbole;
    string type; /* Todo : remplacer par un enum ?*/
    Couleur couleur;
    bool espion; //pour Incognito

    public:
    Piece(char s, Joueur *j, string t);
    Piece(Couleur couleur, Joueur *j, bool espion);
    char getSymbole() const;
    Joueur * getProprietaire() const;
    string getType() const;
    void setType(string s);
    bool estEspion() const;
    Couleur getCouleur() const;
};

std::ostream& operator<<(std::ostream &os, const Piece& piece);




#endif