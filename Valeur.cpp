#include"Valeur.h"

/* Constructor */
Valeur::Valeur(bool b):val_(b){
}

/*Calcule() method */
bool Valeur::Calcule(bool* b) const{
return val_;
}

/*Affiche() method */
std::string Valeur::Affiche() const{
return  (val_) ? std::string("True") : std::string("False");
}

/* Destructor */
void Valeur::Unasigne() {
  delete this;
}

/* Copy() method */
Noeud* Valeur::Copy() const{
return new Valeur(val_);
}

/* GetNods method */
void Valeur::GetNods(Noeud** tab,int* posit){
  tab[*posit]=this;
  *posit = *posit+1;
}
