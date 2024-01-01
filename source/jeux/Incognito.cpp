#include "../../header/Incognito.hpp"
#include "../../header/Piece.hpp"


//création d'un plateau de 10 cases
Incognito::Incognito() : Jeux(5){}

void Incognito::remplirPlateau(Joueur *j1, Joueur *j2){
    cout << "je vais ici" << endl;
    this->getPlateau()->remplirPlateauIncognito(j1,j2);
}

bool Incognito::deplacement(Joueur * j, int x1, int y1, int x2, int y2){
    return this->getPlateau()->deplacementIncognito(j,x1,y1,x2,y2);
}

bool Incognito::interroger(int xQuestionneur, int yQuestionneur, int xInterrogateur, int yInterrogateur){
    return this->getPlateau()->interroger(xQuestionneur,yQuestionneur,xInterrogateur,yInterrogateur);
}

//TODO
bool Incognito::verifFinDePartie(){
 // faut faire d'abord la fonction d'interogation
}
