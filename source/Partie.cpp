#include "../header/Partie.hpp"

Partie::Partie(){}

Partie::Partie(Jeux *j,string ps1, string ps2){
    type_de_jeu = j;
    joueur_1 = new Joueur{ps1,1};
    joueur_2 = new Joueur{ps2,2};
}

Joueur * Partie::getJoueur1() const{
    return joueur_1;
}

Joueur * Partie::getJoueur2() const{
    return joueur_2;
}

void Partie::launch(){
    int tour = 1;
    type_de_jeu->remplirPlateau(joueur_1,joueur_2);
    while(!type_de_jeu->verifFinDePartie()){ /* tmp*/
        cout << "Tour " << tour << endl;
        cout << *type_de_jeu->getPlateau() << endl;
        cout << "Au tour de " << *joueur_1 << endl;
        jouerTour(joueur_1);
        cout << *type_de_jeu->getPlateau() << endl;
        cout << "Au tour de " << *joueur_2 << endl;
        jouerTour(joueur_2);
    }
}



void Partie::jouerTour(Joueur *j1){
    bool played = false;
    while(!played){
        string action = "";
        string coords = "";
        cout << "Que voulez-vous faire (choisir le chiffre) ?" << endl << "1. Déplacer une pièce \n2. Print : Affiche le plateau de jeu \n3. Match nul" << endl;
        cin >> action;
        int num_action = stoi(action);


        switch(num_action){
            case 1: {
                cout << "Insérer dans l'ordre suivant : x1 y1 x2 y2" << endl;
                string x1,y1,x2,y2;
                cin >> x1; cin >> y1; cin >> x2; cin >> y2;

                if(type_de_jeu->deplacement(j1,stoi(x1),stoi(y1),stoi(x2),stoi(y2))){
                    played = true;
                } else {
                    cout << "Erreur : déplacement impossible" << endl;
                } break;
            }
                case 2: {
                cout << *type_de_jeu->getPlateau() << endl; break;
                }

                case 3: {
                    if(matchNul(joueur_2)){
                        type_de_jeu->matchNul();
                    }
                }

        }
    }
}

bool Partie::matchNul(Joueur *j2){
        cout << "Votre adersaire vous propose un match nul (Insérer le chiffre). \n1. Non    2.Ok" << endl;
        string rep;
        cin >> rep;
        int num = stoi(rep);
        if (num == 2){return true;} else {return false;}
}
    





