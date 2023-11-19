#include "../../header/Dames.hpp"






Dames::Dames() : Jeux(10){}


void Dames::remplirPlateau(Joueur *j1, Joueur *j2){
    cout << "je vais ici" << endl;
    this->getPlateau()->remplirPlateauDames(j1,j2);
}

bool Dames::deplacement(Joueur * j, int x1, int y1, int x2, int y2){
    if (x1 < 0 || x1 > 9 || y1 < 0 || y1 > 9 || x2 < 0 || x2 > 9 || y1 < 0 || y2 > 9){ return false;}
    return this->getPlateau()->deplacementDames(j,x1,y1,x2,y2);
}

bool Dames::verifFinDePartie(){
    return (noir <= 0 || blanc <= 0);
}

