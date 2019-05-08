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
void Valeur::GetNods(Noeud** tab,int* posit){
  tab[*posit]=this;
  *posit = *posit+1;
}
