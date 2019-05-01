#include"Valeur.h"

Valeur::Valeur(bool b):val_(b){
}

bool Valeur::Calcule(bool*) const{
return val_;
}
