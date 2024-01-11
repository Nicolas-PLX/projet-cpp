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
    vector<Piece *> piece_suppr = vector<Piece *>(); /*Liste des pièces a supprimer*/
    vector<pair<int, int>> coord_piece_suppr = vector<pair<int, int>>(); //Coordonnées des vecteurs supprimés
    bool fin_du_tour = false; /* bool qui nous servira à stopper le déplacement si le joueur ne peut plus se déplacer*/

    vector<pair<int,int>> coord_peut_jouer = vector<pair<int, int>>();
    bool a_joue = false; /* bool qui nous indique si le joueur a déjà joué, et doit continuer de prendre des pièces*/

    Piece *p = damier[x1][y1]->getPiece();
    if (p->getProprietaire()->getId() != j->getId()){
        return false; // SI la pièce que le joueur essaye de déplacé n'est pas la sienne, return false
    }
    while(!fin_du_tour){        
        cout << a_joue << endl;
        cout << "fin du tour" << endl;
        cout << p->getType() << endl;
        if(a_joue && coord_peut_jouer.empty()){ /*Si on a déjà joué et qu'il n'y a plus de déplacement possible, on a fini de se déplacer*/
            fin_du_tour = true;
            char s = damier[x2][y2]->getPiece()->getSymbole();
            if(!piece_suppr.empty()){
                transformationDame(s,x2,y2);
            }
        } else {
            if (a_joue){
                x1 = x2; y1 = y2;
                x2 = coord_peut_jouer[0].first; y2 = coord_peut_jouer[0].second;
                cout << x2 << " " << y2 << endl;
                coord_peut_jouer.clear();
            }
            // Déplacement diagonale ou non
            int deltaX = x2 - x1;
            int deltaY = y2 - y1;
            if(abs(deltaX) != abs(deltaY)){
            fin_du_tour = true;
            return false;
            }
            if (p->getType() == "pion"){ // On se déplace en fonction du type de pièce que nous avons
                cout << "je vais ici  pion" << endl;
                cout << a_joue << endl;
                if(checkDeplacementPion(j,x1,y1,x2,y2)){
                    bool prend_pion = checkSaut(x1,y1,x2,y2);
                    if (prend_pion){
                        suppressionPiece(piece_suppr,(x1+x2)/2,(y1+y2)/2,coord_piece_suppr);
                    }
                    /* Deplacement de la pièce : elle va en [x2,y2], disparait de [x1,y1]*/
                    damier[x2][y2]->setPiece(p);
                    damier[x1][y1]->setPiece(nullptr);
                    a_joue = true;
                    if (prend_pion){
                        coord_peut_jouer = peutRejouer(j,x2,y2,(x1+x2)/2,(y1+y2)/2);
                        if(!coord_peut_jouer.empty()){
                            /*
                            x1 = x2; y1 = y2;
                            x2 = coord_peut_jouer[0].first; y2 = coord_peut_jouer[0].second;
                            cout << x2 << " " << y2 << endl;
                            */
                        } else {
                            fin_du_tour = true;
                        }
                    } else {
                        fin_du_tour = true;
                        
                    }
                }
                
            } else if (p->getType() == "dame"){
                cout << "je vais ici : dame" << endl;
                if (checkDeplacementDame(j,x1,y1,x2,y2))
                {
                    int directionX =(deltaX > 0) ? 1 : -1;
                    int directionY = (deltaY > 0) ? 1 : -1;
                    for (int i = 1; i < abs(deltaX); i++){
                        int x3 = x1 + i * directionX;
                        int y3 = y1 + i * directionY;
                    if (damier[x3][y3]->getPiece() != nullptr){
                        suppressionPiece(piece_suppr,x3,y3,coord_piece_suppr);
                    }
                    damier[x2][y2]->setPiece(p);
                    damier[x1][y1]->setPiece(nullptr);

                    fin_du_tour = true;
                    }
                }           
            }
        }
        
    }
    if(!piece_suppr.empty()){
        vidage(piece_suppr,coord_piece_suppr);
    }
    return true;
}

bool Plateau::checkDeplacementPion(Joueur *j, int x1, int y1, int x2, int y2){
    if(!checkDeplacementJoueur(x1,y1,x2,y2)){
        return false;
    }
    /* Cas où c'est un simple déplacement*/
    int deltaX = x2 - x1;
    if(abs(deltaX) == 1){
        if (damier[x2][y2]->getPiece() == nullptr){
            return true;
        }

        /* Cas où le déplacement est un saut*/
    } else if(abs(deltaX) == 2){
        if (damier[x2][y2]->getPiece() == nullptr){
        /* Puis on regarde si c'est un pion de l'autre joueur */
            if (damier[(x1+x2)/2][(y1+y2)/2]->getPiece()->getProprietaire() != j){
                return true;
            }
        }
    }
    return false;
}

bool Plateau::checkDeplacementDame(Joueur *j, int x1, int y1, int x2, int y2){
    int compteur_pion_adv = 0;
    /* On regarde si le déplacement est er'cn diagonale*/
    int deltaX = x2 - x1;
    int deltaY = y2 - y1;
    if(abs(deltaX) != abs(deltaY)){
        return false;
    }
    /* Au lieu de faire chaque cas de diagonale, on récupère le sens du déplacement en regardant si on avance vers le haut (x1 > x2) ou vers le bas (x1 < x2)
        Ensuite, on multipliera par 1 ou -1 pour changé la valeur de l'indice i en fonction du résultat obtenu juste avant, pour pouvoir faire les 4 cas
        de diagonales en même temps.
    */
    int directionX =(deltaX > 0) ? 1 : -1;
    int directionY = (deltaY > 0) ? 1 : -1;

    /*On regarde s'il n'y a pas de dames amis entre la case de départ et celle de fin*/
    /* On va aussi compter le nombre de pièce de l'adversaire, il ne peut pas y en avoir plus de 1*/
    for (int i = 1; i < abs(deltaX); i++){
        int x3 = x1 + i * directionX;
        int y3 = y1 + i * directionY;
        if (damier[x3][y3]->getPiece() != nullptr){
            if(damier[x3][y3]->getPiece()->getProprietaire()->getId() == j->getId()){
                return false;
            } else {
                compteur_pion_adv++;
            }
        }
    }
    if (compteur_pion_adv > 1){
        return false;
    }
    if(damier[x2][y2]->getPiece() == nullptr){
        return true;
    }
    return false;
}

bool Plateau::checkDeplacementJoueur(int x1, int y1, int x2, int y2){ //Un pion d'un joueur ne peut qu'aller tout droit en face de lui
        //On regarde d'abord la couleur du pion qui essaye d'avancer
        char s = damier[x1][y1]->getPiece()->getSymbole();
        if(s == 'N'){ //Cas joueur du haut
            if (x1 < x2){
                return true;
            }
        } else {
            if (x1 > x2){
                return true;
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

/*Fonction qui regarde s'il y a une pièce à une position donnée*/
bool Plateau::checkPiece(int x, int y){
    cout << *damier[x][y]->getPiece()->getProprietaire() << endl;
    cout << *damier[x][y]->getPiece() << endl;
    if(damier[x][y]->getPiece()){return true;}
    return false;
}

void Plateau::suppressionPiece(vector<Piece *>& vp,int x,int y,vector<pair<int, int>>& coords){
    Piece *p = damier[x][y]->getPiece();
    cout << "l'ajout a-t-il été fait ?" << endl;
    vp.push_back(p);
    pair<int,int> np(x,y);
    coords.push_back(np);
    for(int i = 0; i < coords.size();i++){
        cout << coords[i].first << " " << coords[i].second << endl;
    }
  
}

/* Fonction qui regarde si c'est un saut ou un simple déplacement*/
bool checkSaut(int x1, int y1, int x2, int y2){

    if ((x2 == x1 + 2 && y2 == y1 + 2) // déplacement -> Diagonale Bas Droit
    || (x2 == x1 +2 && y2 == y1 - 2) // déplacement -> Diagonale Bas Gauche
    || (x2 == x1 - 2 && y2 == y1 +2) // déplacement -> Diagonale Haut Droit
    || (x2 == x1 - 2 && y2 == y1 - 2)){
        return true;
    }
    return false;
}

void Plateau::vidage(vector<Piece *>& vp, vector<pair<int, int>>& coords){
    for(Piece *p : vp){
        delete p;
    }
    vp.clear();
    for(pair<int,int> p : coords){
        damier[p.first][p.second]->setPiece(nullptr);
    }
}

vector<pair<int, int>> Plateau::peutRejouer(Joueur *j, int x, int y, int xp, int yp){
    vector<pair<int, int>> liste_coords = vector<pair<int, int>>(); /* liste des coordonnées où le joueur peut se déplacer*/
    Piece *p = damier[x][y]->getPiece();
    cout << "je vais jusqu'ici" << endl;
    cout << x << " " << y << " " << xp << " " << yp << endl;
    cout << x +2 << " " << taille << " " << y +2 << endl;
    if (p->getType() == "pion"){
        if(x+2 > 0 && x+2 < taille && y+2 > 0 && y+2 < taille){
            if(damier[x+2][y+2]->getPiece() == nullptr &&
             (x+1 != xp || y+1 != yp)){
                if(damier[x+1][y+1]->getPiece() != nullptr){
                    if (damier[x+1][y+1]->getPiece()->getProprietaire()->getId() != j->getId()){
                        pair<int,int> np(x+2,y+2);
                        liste_coords.push_back(np);
                        for(int i = 0; i < liste_coords.size();i++){
                            cout << liste_coords[i].first << " " << liste_coords[i].second << endl;
                        }
                    }
                
                }
            }
        }
        if(x+2 > 0 && x+2 < taille && y-2 > 0 && y-2 < taille){
            cout << "je vais la avant de mourir" << endl;
            cout << x+1 << " "<< y-1 << endl;
            if(damier[x+1][y-1]->getPiece() == nullptr){
                cout << "test" << endl;
            }
            if(damier[x+2][y-2]->getPiece() == nullptr && (x+1 != xp || y-1 != yp)){
                cout << "test2" << endl;
            }
            if(damier[x+2][y-2]->getPiece() == nullptr && 
            damier[x+1][y-1]->getPiece() != nullptr &&
            (x+1 != xp || y-1 != yp)){
                if( damier[x+1][y-1]->getPiece()->getProprietaire()->getId() != j->getId()){
                    cout << "je suis ici" << endl;
                    pair<int,int> np(x+2,y-2);
                    cout << np.first << " " << np.second << endl;
                    liste_coords.push_back(np);
                    for(int i = 0; i < liste_coords.size();i++){
        cout << liste_coords[i].first << "|2| " << liste_coords[i].second << endl;
                    }                     
                }
            
                }
        }
        if(x-2 > 0 && x-2 < taille && y+2 > 0 && y+2 < taille){
            if(damier[x-2][y+2]->getPiece() == nullptr &&
             damier[x-1][y+1]->getPiece() != nullptr &&
             (x-1 != xp || y+1 != yp)){
                if(damier[x-1][y+1]->getPiece()->getProprietaire()->getId() != j->getId()){
                    pair<int,int> np(x-2,y+2);
                
                liste_coords.push_back(np);
                for(int i = 0; i < liste_coords.size();i++){
        cout << liste_coords[i].first << " |3|" << liste_coords[i].second << endl;
    }

                }
               
                }
        }
        if(x-2 > 0 && x-2 < taille && y-2 > 0 && y-2 < taille){
            if(damier[x-2][y-2]->getPiece() == nullptr &&
             damier[x-1][y-1]->getPiece() != nullptr &&
             (x-1 != xp || y-1 != yp)){
                if(damier[x-1][y-1]->getPiece()->getProprietaire()->getId() != j->getId()){
                pair<int,int> np(x-2,y-2);
                
                liste_coords.push_back(np);
                for(int i = 0; i < liste_coords.size();i++){
        cout << liste_coords[i].first << "|4| " << liste_coords[i].second << endl;
    }
                }
                
                }
        }

    }
    return liste_coords;
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
    //remplir les pieces noirs et blanches
   for(int i =2; i < taille; i++){
        for( int j = 0; j<=i-2 && j<= 2 ;  j++){
            damier[i][j]->setPiece(new Piece{'B',j1,false});
            damier[j][i]->setPiece(new Piece{'N',j2,false});
        }
    }
    //le espion noir et blanc
    damier[2][4]->setPiece(new Piece{'N',j2,true});
    damier[2][0]->setPiece(new Piece{'B',j1,true});
    //les chateaux
    damier[0][taille-1]->setPiece(nullptr);
    damier[taille-1][0]->setPiece(nullptr); 
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
    if (damier[x1][y1]->getPiece() == nullptr 
    || damier[x1][y1]->getPiece()->getProprietaire()->getId() != j->getId()){
        cout << "Vous n'avez de piece dans la case de depart!" <<endl;
        return false;
    }
    //On verifie si la case d'arrivée est libre
    if(damier[x2][y2]->getPiece() != nullptr){
        cout << "La case d'arrivée est dèja occupée!" <<endl;
        return false;
    }
    //On verifie si la case d'arrivée n'est pas le chateau
    if((x2 == taille-1 && y2 == 0) || (x2 == 0 && y2 == taille-1)){
        cout << "La case d'arrivée est un chateau!" <<endl;
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

    int& pion = (damier[xQuestionneur][xQuestionneur]->getPiece()->getSymbole() == 'N') ? noir : blanc;
    int& espionadv = (damier[xQuestionneur][xQuestionneur]->getPiece()->getSymbole() == 'N') ? espblanc : espnoir;
    int& espion = (damier[xQuestionneur][xQuestionneur]->getPiece()->getSymbole() == 'N') ? espnoir : espblanc;
    // Si le pion interrogé est un espion, le questionneur gagne
    if (damier[xInterrogateur][yInterrogateur]->getPiece()->estEspion()) {
        std::cout << "Le questionneur a gagné !" << std::endl;
        espionadv = 0;
        return true;
    }
    // Sinon, le questionneur perd son pion interrogateur
    damier[xQuestionneur][yQuestionneur]->setPiece(nullptr);
    pion--;
    // Si le pion interrogateur est l'espion du questionneur, le questionneur perd la partie
    if (damier[xQuestionneur][yQuestionneur]->getPiece()->estEspion()) {
        std::cout << "Le questionneur a perdu la partie !" << std::endl;
        espion = 0;
        return true;
    } 
    return true;
}

bool Plateau::checkChateau(){
    // Pour le joueur Noir (espionBlanc atteint le château)
    if ((damier[taille-2][0]->getPiece() != nullptr && damier[taille-2][0]->getPiece()->estEspion() &&
    damier[taille-2][0]->getPiece()->getSymbole() == 'N') ||(damier[taille-1][1]->getPiece() != nullptr
    && damier[taille-1][1]->getPiece()->estEspion() && damier[taille-1][1]->getPiece()->getSymbole() == 'N') )
    {
        std::cout << "L'espion Noir a atteint le château de l'adversaire ! " << std::endl;
        return true;
    }

    // Pour le joueur Blanc (espionNoir atteint le château)
    if ((damier[0][taille-2]->getPiece() != nullptr && damier[0][taille-2]->getPiece()->estEspion() &&
    damier[0][taille-2]->getPiece()->getSymbole() == 'B') ||(damier[1][taille-1]->getPiece() != nullptr
    && damier[1][taille-1]->getPiece()->estEspion() && damier[1][taille-1]->getPiece()->getSymbole() == 'B') )
    {
        std::cout << "L'espion Blanc a atteint le château de l'adversaire !" << std::endl;
        return true;
    }
    return false;
}

