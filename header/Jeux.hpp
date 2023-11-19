#ifndef _JEUX
#define _JEUX

#include "Plateau.hpp"
#include "Joueur.hpp"

/* CLasse Jeux : tout les jeux devront hérité de celui là, OU ALORS utilisera la généricité, et devra traiter le jeu peu importe de quel type il est réellement */
class Jeux{
    protected:
    Plateau * plateau;

    

    public:
    Jeux(int n);
    Plateau * getPlateau() const;
    virtual void remplirPlateau(Joueur *j1, Joueur *j2);
    virtual bool deplacement(Joueur *joueur, int x1, int y1, int x2, int y2);
    
};


#endif