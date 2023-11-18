#include "../../header/Plateau.hpp"


Plateau::Plateau(int n){
    taille = n;
    damier.resize(n,vector<Case *>(taille,nullptr));
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            damier[i][j] = new Case();
        }
    }
}

int Plateau::getTaille() const{
    return taille;
}

vector<vector<Case *>> Plateau::getDamier() const{
    return damier;
}

std::ostream& operator<<(std::ostream &out, const Plateau& plateau){
    vector<vector<Case *>> d = plateau.getDamier();
    for(int i = 0; i < plateau.getTaille(); i++){
        for(int j = 0; j < plateau.getTaille();j++){
            out << "| " << *d[i][j] << " ";
        } 
        out << "|" << endl << endl;
    }
    return out;
}
