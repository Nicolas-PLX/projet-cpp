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
    if (p->getProprietaire()->getId() != j->getId()){
        cout << "je vais ici : false" << endl;
        return false;
    }
    if (p->getType() == "pion"){
        cout << "je vais ici aussi : pion" << endl;
        if(checkDeplacementPion(j,x1,y1,x2,y2)){
            suppressionPiece(x1,y1,x2,y2);
            /* Deplacement de la pièce : elle va en [x2,y2], disparait de [x1,y1]*/
            damier[x2][y2]->setPiece(p);

            damier[x1][y1]->setPiece(nullptr);

            char s = damier[x2][y2]->getPiece()->getSymbole();
            transformationDame(s,x2,y2);

            return true;
        }
        
    }
    return false;
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
    Piece *p = damier[(x1+x2)/2][(y1+y2)/2]->getPiece();
    cout << "je vais ici avant le delete" << endl;
    cout << *p << endl;
    if(p != nullptr){
        cout << "je vais ici : delete" << endl;
        delete p;
        //damier[(x1+x2)/2][(y1+y2)/2]->setPiece(nullptr);
    }
}


std::ostream& operator<<(std::ostream &out, const Plateau& plateau){
    vector<vector<Case *>> d = plateau.getDamier();
    for (int i = 0; i < plateau.getTaille(); i++){
        out << "  " << i << " ";
    }
    out << endl;
    for(int i = 0; i < plateau.getTaille(); i++){
        out << i;
        for(int j = 0; j < plateau.getTaille();j++){
            out << "| " << *d[i][j] << " ";
        } 
        out << "|" << endl << endl;
    }
    return out;
}

//Partie Incognito******************************************************************************************
//Remplir la plateu au début de la partie
void Plateau::remplirPlateauIncognito(Joueur *j1, Joueur *j2){
    //remplir les pieces blanches
    for(int i =0; i < taille; i++){
        for( int j = i+2; j<i+4 && j< taille; j++){
            damier[i][j]->setPiece(new Piece{Couleur::Blanc,j1,false});
        }
    }
    //le pion blanc
    damier[0][2]->setPiece(new Piece{Couleur::Blanc,j1,true});
    //remplir les pieces noirs et blanches
    for(int i =2; i < taille; i++){
        for( int j = 0; j<i; j++){
            damier[i][j]->setPiece(new Piece{Couleur::Blanc,j1,false});
            damier[j][i]->setPiece(new Piece{Couleur::Noir,j2,false});
        }
    }
    //le pion noir et blanc
    damier[2][4]->setPiece(new Piece{Couleur::Blanc,j1,true});
    damier[2][0]->setPiece(new Piece{Couleur::Noir,j2,true});
}

bool Plateau::deplacementIncognito(Joueur *j, int x1, int y1, int x2, int y2){
    //On verifie si les coordonnées sont valides
    if(x1 < 0 || x2 < 0 || x1 > taille || x2 > taille ||y1 < 0 || y2 < 0 ||
     y1 > taille || y2 > taille){
        cout << "Coordonnées invalides!" << endl;
        return false;
    }
    //On verifie s'il change de position ou il reste dans la meme case
    if(x1 == x2 && y1 == y2){
        cout << "Aucun déplacement!" << endl;
        return false;
    }
    //On verifie s'il sagit de son propre pion
    if (damier[x1][y1]->getPiece() == nullptr || damier[x1][y1]->getPiece()->getProprietaire()->getId() != j->getId()){
        cout << "Vous n'avez de piece dans la case de depart!" <<endl;
        return false;
    }
    //On verifie si la case d'arrivée est libre
    if(damier[x2][y2]->getPiece() != nullptr){
        cout << "La case d'arrivée est dèja occupée!" <<endl;
        return false;
    }
    //On vérifie si le déplacement est autorisé selon les regles du Incognito
    if(checkDeplacementIncognito(x1,y1,x2,y2)){
        Piece *p = damier[x1][y1]->getPiece();
        damier[x2][y2]->setPiece(p);
        damier[x1][y1]->setPiece(nullptr);
        return true;
    }
    else{
        cout << "Deplacement invalides!" << endl;
        return false;
    }
}

bool Plateau::checkDeplacementIncognito(int x1, int y1, int x2, int y2){
    if(x1 == x2 && y1 != y2){
        cout << "Déplacement vertical" << endl;
    }
    else if(y1 == y2 && x1 != x2){
        cout << "Déplacement horizontal" << endl;
    }
    else if(abs(x1 - x2) == abs(y1 - y2)){
        cout << "Déplacement diagonal" << endl;
    }
    else {
        return false;
    }

    int x = x2 - x1;
    int y = y2 - y1;

    //On verifie la direction du déplacement
    int dx = (x > 0)? 1 : ((x < 0)? -1 : 0);
    int dy = (y > 0)? 1 : ((y < 0)? -1 : 0);

    //On verifie s'il n y a pas une case occupée entre la case de depart et celle d'arrivée
    for(int i = x1 + dx, j = y1 + dy ; i!= x2 || j != y2; i+=dx, j+=dy){
        // on a trouvé une case occupé
        if(damier[i][j]->getPiece() != nullptr){
            return false;
        }
    }
    return true;
} 

bool Plateau::sontVoisinsOrthogonaux(int x1, int y1, int x2, int y2) const {
    return (std::abs(x1 - x2) == 1 && y1 == y2) || (x1 == x2 && std::abs(y1 - y2) == 1);
}

bool Plateau::interroger(Joueur * j, int xQuestionneur, int yQuestionneur, int xInterrogateur, int yInterrogateur, int& noir, int& blanc,int& espnoir, int& espblanc){
    if (!(xQuestionneur >= 0 && xQuestionneur < taille && yQuestionneur >= 0 && yQuestionneur < taille) || !(xInterrogateur >= 0 && xInterrogateur < taille && yInterrogateur >= 0 && yInterrogateur < taille)) {
        std::cout << "Coordonnées invalides." << std::endl;
        return false;
    }
    // Vérifier si les pions sont voisins orthogonaux
    if (!sontVoisinsOrthogonaux(xQuestionneur, yQuestionneur, xInterrogateur, yInterrogateur)) {
        std::cout << "Les pions ne sont pas voisins orthogonaux." << std::endl;
        return false;
    }
    //mise a jour du nombre de pion et d'espion 

    int& pion = (damier[xQuestionneur][xQuestionneur]->getPiece()->getCouleur() == Couleur::Noir) ? noir : blanc;
    int& espionadv = (damier[xQuestionneur][xQuestionneur]->getPiece()->getCouleur() == Couleur::Noir) ? espblanc : espnoir;
    int& espion = (damier[xQuestionneur][xQuestionneur]->getPiece()->getCouleur() == Couleur::Noir) ? espnoir : espblanc;
    // Si le pion interrogé est un espion, le questionneur gagne
    if (damier[xInterrogateur][yInterrogateur]->getPiece()->estEspion()) {
        std::cout << "Le questionneur gagne !" << std::endl;
        espionadv = 0;
        return true;
    }
    // Sinon, le questionneur perd son pion interrogateur
    damier[xQuestionneur][yQuestionneur]->setPiece(nullptr);
    pion--;
    // Si le pion interrogateur est l'espion du questionneur, le questionneur perd la partie
    if (damier[xQuestionneur][yQuestionneur]->getPiece()->estEspion()) {
        std::cout << "Le questionneur perd la partie !" << std::endl;
        espion = 0;
        return true;
    } 
    return true;
}

bool Plateau::checkChateau(){
    // Pour le joueur Noir (espionBlanc atteint le château)
    if ((damier[taille-2][0]->getPiece() != nullptr && damier[taille-2][0]->getPiece()->estEspion() &&
    damier[taille-2][0]->getPiece()->getCouleur() == Couleur::Blanc) ||(damier[taille-1][1]->getPiece() != nullptr
    && damier[taille-1][1]->getPiece()->estEspion() && damier[taille-1][1]->getPiece()->getCouleur() == Couleur::Blanc) )
    {
        std::cout << "L'espion Blanc a atteint le château de l'adversaire !" << std::endl;
        return true;
    }

    // Pour le joueur Blanc (espionNoir atteint le château)
    if ((damier[0][taille-2]->getPiece() != nullptr && damier[0][taille-2]->getPiece()->estEspion() &&
    damier[0][taille-2]->getPiece()->getCouleur() == Couleur::Noir) ||(damier[1][taille-1]->getPiece() != nullptr
    && damier[1][taille-1]->getPiece()->estEspion() && damier[1][taille-1]->getPiece()->getCouleur() == Couleur::Noir) )
    {
        std::cout << "L'espion Noir a atteint le château de l'adversaire !" << std::endl;
        return true;
    }

    return false;
}

