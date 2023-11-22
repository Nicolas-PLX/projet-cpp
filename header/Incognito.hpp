#ifndef _INCOGNITO
#define _INCOGNITO 

#include "Jeux.hpp"
#include <string>

/* Incognito le jeu*/
class Incognito : public Jeux{
    protected:
    int noir = 4;
    int espionNoir = 1;
    int blanc = 4;
    int espionBlanc = 1;


    public:
        Incognito();
        virtual void remplirPlateau(Joueur *j1, Joueur *j2) override;
        virtual bool deplacement(Joueur *joueur, int x1, int y1, int x2, int y2) override;
        bool verifFinDePartie();
};

#endif