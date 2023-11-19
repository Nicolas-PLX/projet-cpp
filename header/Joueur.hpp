#ifndef _JOUEUR
#define _JOUEUR

#include <iostream>
#include <string>
using namespace std;

class Joueur{
    protected:
    string pseudo;
    /* En rajouter */

    public:
    Joueur(string ps);
    string getPseudo() const;

};

#endif 