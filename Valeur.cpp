#include"Valeur.h"

Valeur::Valeur(bool b):val_(b){
}

bool Valeur::Calcule(bool* b) const{

return val_;
}

std::string Valeur::Affiche() const{

return  (val_) ? std::string("True") : std::string("False");


}

void Valeur::Unasigne() {
  delete this;
}

Noeud* Valeur::Copy() const{
return new Valeur(val_);

}
