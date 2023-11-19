#include "../../header/Dames.hpp"






Dames::Dames(string ps1, string ps2) : Jeux(10){
    joueur_1 = new Joueur(ps1);
    joueur_2 = new Joueur(ps2);
}


void Dames::remplirPlateau(){
    cout << "je vais ici" << endl;
    this->getPlateau()->remplirPlateauDames(this->getJoueur1(),this->getJoueur2());
}

bool Dames::deplacement(Joueur * j, int x1, int y1, int x2, int y2){
    if (x1 < 0 || x1 > 9 || y1 < 0 || y1 > 9 || x2 < 0 || x2 > 9 || y1 < 0 || y2 > 9){ return false;}
    return this->getPlateau()->deplacementDames(j,x1,y1,x2,y2);
}

