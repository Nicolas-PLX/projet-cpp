
#include "header/Plateau.hpp"
#include "header/Case.hpp"
#include "header/Piece.hpp"
#include "header/Dames.hpp"
#include "header/Partie.hpp"
#include <iostream>

using namespace std;

int main(){

    /*
    Plateau p{8};
    cout << p << endl;

    Piece piece1{'C'};

    p.getDamier()[0][5]->setPiece(&piece1);
    cout << p << endl;
    */

  // Dames *d = new Dames();
  // Partie *p = new Partie(d,"abc","def");
  // p->launch();

   Plateau *plat = new Plateau{8};
   cout << *plat << endl;
   Joueur *j = new Joueur{"abc",0};
   Joueur *j2 = new Joueur{"def",1};
   Piece *p1 = new Piece{'N',j,"pion"};
   Piece *p2 = new Piece('B',j2,"pion");
   Piece *p3 = new Piece('B',j2,"pion");
   Piece *p4 = new Piece('B',j2,"pion");
   Piece *p5 = new Piece('B',j2,"pion");
   plat->getDamier()[1][1]->setPiece(p1);
   plat->getDamier()[2][2]->setPiece(p2);
   plat->getDamier()[2][4]->setPiece(p5);
   plat->getDamier()[4][4]->setPiece(p3);
   plat->getDamier()[6][4]->setPiece(p4);
   cout << *plat << endl;

   plat->deplacementDames(j,1,1,3,3);
   cout << *plat << endl;
   cout << plat->getDamier()[7][3]->getPiece()->getType() << endl;

}