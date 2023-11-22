#include "../../header/Dames.hpp"






Dames::Dames() : Jeux(10){}


void Dames::remplirPlateau(Joueur *j1, Joueur *j2){
    this->getPlateau()->remplirPlateauDames(j1,j2);
}

bool Dames::deplacement(Joueur * j, int x1, int y1, int x2, int y2){
    if (x1 < 0 || x1 > 9 || y1 < 0 || y1 > 9 || x2 < 0 || x2 > 9 || y1 < 0 || y2 > 9){ return false;}
    return this->getPlateau()->deplacementDames(j,x1,y1,x2,y2);
}

bool Dames::verifFinDePartie(){
    return (noir <= 0 || blanc <= 0);
}

void Dames::majScore(){
    vector<vector<Case *>> board = plateau->getDamier();
    int n = 0;
    int b = 0;
    for(int i = 0; i < plateau->getTaille();i++){
        for(int j = 0; j < plateau->getTaille();j++){
            if(board[i][j]->getPiece()->getSymbole() == 'N'){n++;} else {b++;}
        }
    }
    if(n <= noir){noir = n;}
    if (b <= blanc){blanc = b;}
}

void Dames::matchNul(){
    noir = 0; blanc = 0;
}

