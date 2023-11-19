#include "../header/Partie.hpp"

Partie::Partie(){}

Partie::Partie(Jeux *j,string ps1, string ps2){
    type_de_jeu = j;
    joueur_1 = new Joueur{ps1};
    joueur_2 = new Joueur{ps2};
}

void Partie::launch(){
    int tour = 1;
    type_de_jeu->remplirPlateau(joueur_1,joueur_2);
    cout << *type_de_jeu->getPlateau() << endl;
    while(true){ /* tmp*/
        cout << "Tour " << tour << endl;
        cout << "Au tour de " << joueur_1 << endl;
        jouerTour(joueur_1);
        cout << "Au tour de " << joueur_2 << endl;
        jouerTour(joueur_2);
    }
}
// TODO : corriger le bug d'affichage lors du déplacement
// Vérifier que la pièce bouge bien, et non pas qu'elle se reconstruit
// Ou que ce soit une nouvelle carrément
void Partie::jouerTour(Joueur *j1){
    string action;
    cout << "Que voulez-vous faire ?" << endl << "1. move (x1,y1) (x2,y2) : déplace la pièce \n 2. Print : Affiche le plateau de jeu" << endl;
    cin >> action;
    cout << action.substr(0,4) << endl;
    if (action.substr(0,4) == "move"){ //temp
        type_de_jeu->deplacement(j1,3,0,4,1); //test
        cout << *type_de_jeu->getPlateau() << endl;

    }

}

Joueur * Partie::getJoueur1() const{
    return joueur_1;
}

Joueur * Partie::getJoueur2() const{
    return joueur_2;
}
