#ifndef _JOUEUR
#define _JOUEUR

#include <iostream>
#include <string>
using namespace std;

class Joueur{
    protected:
    string pseudo;
    int identifiant;
    /* En rajouter */

    public:
    Joueur(string ps, int id);
    string getPseudo() const;
    int getId() const;

};

std::ostream& operator<<(std::ostream &os, const Joueur& j);


#endif 