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

    /*Classe abstraite : Nous n'avons pas besoin d'écrire les méthodes de ces fonctions*/
    virtual Plateau * getPlateau() const;
    virtual void remplirPlateau(Joueur *j1, Joueur *j2) = 0;
    virtual bool deplacement(Joueur *joueur, int x1, int y1, int x2, int y2) = 0;
    virtual void matchNul() = 0;
    virtual bool verifFinDePartie() = 0;
    
};


#endif