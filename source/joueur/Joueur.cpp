#include "../../header/Joueur.hpp"




Joueur::Joueur(string ps,int id){
    pseudo = ps;
    identifiant = id;
}

string Joueur::getPseudo() const{
    return pseudo;
}

int Joueur::getId() const {
    return identifiant;
}

std::ostream& operator<<(std::ostream &os, const Joueur& j){
    os << j.getPseudo();
    return os;
}

