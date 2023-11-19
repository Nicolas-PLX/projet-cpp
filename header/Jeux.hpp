#ifndef _JEUX
#define _JEUX

#include "Plateau.hpp"
#include "Joueur.hpp"

/* CLasse Jeux : tout les jeux devront hérité de celui là, OU ALORS utilisera la généricité, et devra traiter le jeu peu importe de quel type il est réellement */
class Jeux{
    protected:
    Plateau * plateau;
    Joueur * joueur_1;
    Joueur * joueur_2;
    

    public:
    Jeux(int n);
    Plateau * getPlateau() const;
    Joueur * getJoueur1() const;
    Joueur * getJoueur2() const;
};


#endif