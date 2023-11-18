#ifndef _PIECE
#define _PIECE

#include <iostream>
using namespace std;

class Piece {
    private:
    /*joueur propriétaire*/
    char symbole;

    public:
    Piece(char s);
    char getSymbole() const;
};

std::ostream& operator<<(std::ostream &os, const Piece& piece);




#endif