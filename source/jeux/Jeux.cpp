#include "../../header/Jeux.hpp"



Jeux::Jeux(int n){
    plateau = new Plateau{n};
}



Plateau * Jeux::getPlateau() const{
    return plateau;
}

void Jeux::remplirPlateau(Joueur *j1, Joueur *j2){ //todo
    cout << "remplissage ..." << endl;
}

bool Jeux::deplacement(Joueur *joueur, int x1, int y1, int x2, int y2){ //todo
    return false;
}

bool Jeux::verifFinDePartie(){ //todo
    return false;
}

bool Jeux::interroger(Joueur * j,int xQuestionneur, int yQuestionneur, int xInterrogateur, int yInterrogateur){ //todo
        return false;
}


