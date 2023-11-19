#ifndef _DAMES
#define _DAMES

#include "Jeux.hpp"
#include <string>

class Dames : public Jeux{
    protected:
    int noir = 20; //Todo : mettre à jour continuellement pendant la partie
    int blanc = 20;

    public:
    Dames();
    virtual void remplirPlateau(Joueur *j1, Joueur *j2) override;
    virtual bool deplacement(Joueur *joueur, int x1, int y1, int x2, int y2) override;
    bool verifFinDePartie();
    
};


#endif