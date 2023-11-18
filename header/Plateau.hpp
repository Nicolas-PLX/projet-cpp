#ifndef _PLATEAU
#define _PLATEAU

#include <iostream>
#include "Case.hpp"
#include <vector>
using namespace std;

/* Classe Plateau : sera le plateau de jeu*/

class Plateau{
    protected:
    vector<vector<Case *>> damier;
    int taille;

    public:
    Plateau(int taille); /*Création d'un plateau de taille n * n */
    int getTaille() const;
    vector<vector<Case *>> getDamier() const;
};

std::ostream& operator<<(std::ostream &os, const Plateau& plateau);



#endif