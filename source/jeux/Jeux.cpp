#include "../../header/Jeux.hpp"



Jeux::Jeux(int n){
    plateau = new Plateau{n};
    joueur_1 = new Joueur{"abc"};
    joueur_2 = new Joueur{"def"};
}



Plateau * Jeux::getPlateau() const{
    return plateau;
}

Joueur * Jeux::getJoueur1() const{
    return joueur_1;
}

Joueur * Jeux::getJoueur2() const{
    return joueur_2;
}

