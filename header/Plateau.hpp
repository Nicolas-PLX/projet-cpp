#ifndef _PLATEAU
#define _PLATEAU

#include <iostream>
#include "Case.hpp"
#include "Joueur.hpp"
#include <vector>
using namespace std;

/* Classe Plateau : sera le plateau de jeu*/

class Plateau{
    protected:
    vector<vector<Case *>> damier;
    int taille;

    public:
    Plateau(int taille); /*Création d'un plateau de taille n * n */
    int getTaille() const;
    vector<vector<Case *>> getDamier() const;

    /* Fonction uniquement pour le jeu de dames, on s'occupera de la généricité plus tard*/
    void remplirPlateauDames(Joueur *j1, Joueur *j2);
    bool deplacementDames(Joueur *j, int x1, int y1, int x2, int y2);
    bool checkDeplacementPion(Joueur *j, int x1, int y1, int x2, int y2);
    bool checkDeplacementDame(Joueur *j, int x1, int y1, int x2, int y2);
    void suppressionPiece(int x1,int y1,int x2,int y2);
    void transformationDame(char s,int x,int y);
    void remplirPlateauIncognito(Joueur *j1, Joueur *j2);
    bool deplacementIncognito(Joueur *j, int x1, int y1, int x2, int y2);
    bool checkDeplacementIncognito(int x1, int y1, int x2, int y2);
    bool sontVoisinsOrthogonaux(int x1, int y1, int x2, int y2) const;
    bool interroger(Joueur * j, int xQuestionneur, int yQuestionneur, int xInterrogateur, int yInterrogateur,int& noir, int& blanc,int& espnoir, int& espblanc);
    bool checkChateau();
};

std::ostream& operator<<(std::ostream &os, const Plateau& plateau);



#endif