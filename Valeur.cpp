#include"Valeur.h"

Valeur::Valeur(bool b):val_(b){
}

bool Valeur::Calcule(bool* b) const{

return val_;
}

std::string Valeur::Affiche(bool* b) const{

return  (val_) ? std::string("True") : std::string("False");


}
