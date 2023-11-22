#include "../../header/Incognito.hpp"
#include "../../header/Piece.hpp"


//création d'un plateau de 10 cases
Incognito::Incognito() : Jeux(5){}

void Incognito::remplirPlateau(Joueur *j1, Joueur *j2){
    cout << "je vais ici" << endl;
    this->getPlateau()->remplirPlateauIncognito(j1,j2);
}