
#include "header/Plateau.hpp"
#include "header/Case.hpp"
#include "header/Piece.hpp"
#include "header/Dames.hpp"
#include "header/Partie.hpp"
#include "header/Incognito.hpp"
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

   //Dames *d = new Dames();
   //Incognito *i = new Incognito();
   //Partie *p = new Partie(i,"player1","player2");
   //p->launch();
  // Dames *d = new Dames();
  // Partie *p = new Partie(d,"abc","def");
  // p->launch();

   /*
   Plateau *plat = new Plateau{8};
   cout << *plat << endl;
   Joueur *j = new Joueur{"abc",0};
   Joueur *j2 = new Joueur{"def",1};
   Piece *p2 = new Piece('B',j2,false,"pion");
   Piece *p1 = new Piece('N',j,false,"pion");
      cout << p1->getType() << endl;

   Piece *p3 = new Piece('B',j2,false,"pion");
   Piece *p4 = new Piece('B',j2,false,"pion");
   Piece *p5 = new Piece('B',j2,false,"pion");
   plat->getDamier()[1][1]->setPiece(p1);
   plat->getDamier()[2][2]->setPiece(p2);
   plat->getDamier()[2][4]->setPiece(p5);
   plat->getDamier()[4][4]->setPiece(p3);
   plat->getDamier()[6][4]->setPiece(p4);
   cout << *plat << endl;
//   cout << *p1 << endl;
   plat->deplacementDames(j,1,1,3,3);
   cout << *plat << endl;
   */
   //cout << plat->getDamier()[7][3]->getPiece()->getType() << endl;


   /* LANCEMENT D'UNE PARTIE !!!!!!*/

   string action = "";
   cout << "A quel jeu voulez-vous jouer ?" << endl << "1. Dames        2. Incognito" << endl;
   cin >> action;
   int num_action = stoi(action);
   string pseudo1, pseudo2;
   cout << "Choississez les deux pseudos (mettre un espace entre les deux)" << endl;
   cin >> pseudo1; cin >> pseudo2;
   switch(num_action){
      case 1:{
         Dames *d = new Dames();
         Partie *p = new Partie(d,pseudo1,pseudo2);
         p->launch();
         break;
      }
      case 2:{
         Incognito *i = new Incognito();
         Partie *p = new Partie(i,pseudo1,pseudo2);
         p->launch();
      }
   }

}