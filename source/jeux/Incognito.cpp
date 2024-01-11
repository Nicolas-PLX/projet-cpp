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

bool Incognito::interroger(Joueur * j,int xQuestionneur, int yQuestionneur, int xInterrogateur, int yInterrogateur){
    return this->getPlateau()->interroger(j,xQuestionneur,yQuestionneur,xInterrogateur,yInterrogateur,this->noir, this->blanc,this->espionNoir, this->espionBlanc);
}

bool Incognito::verifFinDePartie(){
 // vérifier le nombre de pion si <= 0
 if ((noir <= 0 && espionNoir <= 0) || (blanc <= 0 && espionBlanc <= 0)) return true;
 //verifier si l'espion est toujours la
 if (espionNoir <= 0 || espionBlanc <= 0) return true;
 //verifier si l'espion a atteint le chateau de l'adversaire
 return this->getPlateau()->checkChateau();
}
