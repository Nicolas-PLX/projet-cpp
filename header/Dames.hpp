#ifndef _DAMES
#define _DAMES

#include "Jeux.hpp"
#include <string>

class Dames : public Jeux{
    public:
    Dames(string ps1, string ps2);
    void remplirPlateau();
    bool deplacement(Joueur *joueur, int x1, int y1, int x2, int y2);
    
};


#endif