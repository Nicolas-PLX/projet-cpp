#include "../../header/Plateau.hpp"


Plateau::Plateau(int n){
    taille = n;
    damier.resize(n,vector<Case *>(taille,nullptr));
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            damier[i][j] = new Case();
        }
    }
}

int Plateau::getTaille() const{
    return taille;
}

vector<vector<Case *>> Plateau::getDamier() const{
    return damier;
}
/*Fonction qui va remplir le plateau. On s'occupe de chaque ligne une a une*/
void Plateau::remplirPlateauDames(Joueur *j1, Joueur *j2){
    // ON remplit pour le joueur 1
    for(int i =0; i < 4;i++){
        for(int j = 0; j < this->getTaille();j++){
            if(i % 2 == 0){
                if(j % 2 == 1){
                    damier[i][j]->setPiece(new Piece{'N',j1,"pion"});
                }
            } else {
                if(j % 2 == 0){
                    damier[i][j]->setPiece(new Piece{'N',j1,"pion"});
                }
            }
        }   
    }
    //On remplit pour le joueur 2
    for(int i = 6; i < this->getTaille();i++){
        for(int j = 0; j < this->getTaille();j++){
            if(i % 2 == 0){
                if(j % 2 == 1){
                    damier[i][j]->setPiece(new Piece{'B',j2,"pion"});
                }
            } else {
                if(j % 2 == 0){
                    damier[i][j]->setPiece(new Piece{'B',j2,"pion"});
                }
            }
        }
    }
}

bool Plateau::deplacementDames(Joueur *j, int x1, int y1, int x2, int y2){
    Piece *p = damier[x1][y1]->getPiece();
    if (p->getType() == "pion"){
        if(checkDeplacementPion(j,x1,y1,x2,y2)){
            suppressionPiece(x1,y1,x2,y2);

            /* Deplacement de la pièce : elle va en [x2,y2], disparait de [x1,y1]*/
            damier[x2][y2]->setPiece(damier[x1][y1]->getPiece());
            damier[x1][y1]->setPiece(nullptr);

            char s = damier[x2][y2]->getPiece()->getSymbole();
            transformationDame(s,x2,y2);
        }
        
    }
}

bool Plateau::checkDeplacementPion(Joueur *j, int x1, int y1, int x2, int y2){
    /* Cas où c'est un simple déplacement*/
    if ((x2 == x1 + 1 && y2 == y1 + 1) // déplacement -> Diagonale Bas Droit
    || (x2 == x1 +1 && y2 == y1 - 1) // déplacement -> Diagonale Bas Gauche
    || (x2 == x1 - 1 && y2 == y1 +1) // déplacement -> Diagonale Haut Droit
    || (x2 == x1 - 1 && y2 == y1 - 1)){ // déplacement -> diagonale Haut Gauche
        if (damier[x2][y2]->getPiece() == nullptr){
            return true;
        }
    }  
    /* Cas où nous sautons au dessus d'un autre pion */
    /* On regarde d'abord si c'est bien un déplacement en diagonale valide*/
    if ((x2 == x1 + 2 && y2 == y1 + 2) // déplacement -> Diagonale Bas Droit
    || (x2 == x1 +2 && y2 == y1 - 2) // déplacement -> Diagonale Bas Gauche
    || (x2 == x1 - 2 && y2 == y1 +2) // déplacement -> Diagonale Haut Droit
    || (x2 == x1 - 2 && y2 == y1 - 2)){ // déplacement -> diagonale Haut Gauche
        /* on regarde si la case est vide*/
        if (damier[x2][y2]->getPiece() == nullptr){
        /* Puis on regarde si c'est un pion de l'autre joueur */
            if (damier[(x1+x2)/2][(y1+y2)/2]->getPiece()->getProprietaire() != j){
                return true;
            }
        }
        
    }
    return false;
}

void Plateau::transformationDame(char s,int x, int y){
    if (s == 'N'){ // Joueur qui commence en haut, donc le pion doit se trouver sur la dernière ligne
        if (x == taille-1){
            damier[x][y]->getPiece()->setType("dame");
        }
    } else {
        if (s == 'B'){
            if (x == 0){
                damier[x][y]->getPiece()->setType("dame");
            }
        }
    }
}

void Plateau::suppressionPiece(int x1,int y1,int x2,int y2){
        delete damier[(x1+x2)/2][(y1+y2)/2]->getPiece();
        damier[(x1+x2)/2][(y1+y2)/2]->setPiece(nullptr);
}


std::ostream& operator<<(std::ostream &out, const Plateau& plateau){
    vector<vector<Case *>> d = plateau.getDamier();
    for(int i = 0; i < plateau.getTaille(); i++){
        for(int j = 0; j < plateau.getTaille();j++){
            out << "| " << *d[i][j] << " ";
        } 
        out << "|" << endl << endl;
    }
    return out;
}
