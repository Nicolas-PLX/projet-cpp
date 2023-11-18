#ifndef _CASE
#define _CASE

#include "Piece.hpp"
#include <iostream>



/* Classe temporaire, pas sûr que nous en ayons réellement besoin ?*/
class Case{
    protected:
    Piece *piece;

    public:
    Case();
    Case(Piece *p);
    Piece * getPiece() const;
    void setPiece(Piece *p); 
};

std::ostream& operator<<(std::ostream &os, const Case& c);

#endif