#ifndef _PARTIE
#define _PARTIE

#include "Jeux.hpp"
#include "Joueur.hpp"
#include "Dames.hpp"
#include <string>

/* CLasse Partie : cette classe consistera à prendre un jeu, et de lancer une partie de ce jeu. */

/* /!\ je risque de changé la classe, c'est surtout pour tester temporairement*/
class Partie{
    protected:
    Jeux *type_de_jeu;
    Joueur * joueur_1;
    Joueur * joueur_2;

    public:
    Partie();
    Partie(Jeux *t, string pseudo1, string pseudo2);
    Joueur * getJoueur1() const;
    Joueur * getJoueur2() const;
    void launch();
    void jouerTour(Joueur *j);
    

};
#endif