#include "../../header/Joueur.hpp"




Joueur::Joueur(string ps){
    pseudo = ps;
}

string Joueur::getPseudo() const{
    return pseudo;
}