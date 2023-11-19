
#include "header/Plateau.hpp"
#include "header/Case.hpp"
#include "header/Piece.hpp"
#include "header/Dames.hpp"
#include "header/Partie.hpp"
#include <iostream>

using namespace std;
/*Classe Main, c'est ici qu'on testera le code, puis que l'on éxecutera tout cela */

int main(){

    /*
    Plateau p{8};
    cout << p << endl;

    Piece piece1{'C'};

    p.getDamier()[0][5]->setPiece(&piece1);
    cout << p << endl;
    */

   Dames *d = new Dames();
   Partie *p = new Partie(d,"abc","def");
   p->launch();

}