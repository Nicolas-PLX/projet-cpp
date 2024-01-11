#ifndef _DAMES
#define _DAMES

#include "Jeux.hpp"
#include <string>

class Dames : public Jeux{
    protected:
    int noir = 20;
    int blanc = 20;

    public:
    Dames();
    int getNoir();
    int getBlanc();
    virtual void remplirPlateau(Joueur *j1, Joueur *j2) ;
    virtual bool deplacement(Joueur *joueur, int x1, int y1, int x2, int y2) ;
    virtual void matchNul() ;
    virtual bool verifFinDePartie() ;
    void majScore(); /* Fonction qui met à jour le score de la partie*/
    bool peutRejouer(Joueur *j,int x1, int y2);
    
};


#endif