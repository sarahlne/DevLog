#include"Ou.h"

/* Constructor */
Ou::Ou(Noeud* N1,Noeud* N2){
Noeud1_=N1;
Noeud2_=N2;
}

/*Calcul method */
bool Ou::Calcule(bool* b) const{
return Noeud1_->Calcule(b) or Noeud2_->Calcule(b);
}

/*Affiche() method */
std::string Ou::Affiche() const{
return  "("+Noeud1_->Affiche() +" Or "+ Noeud2_->Affiche()+")";
}

/* Destructor */
void Ou::Unasigne(){
  Noeud1_->Unasigne();
  Noeud2_->Unasigne();
  delete this;
}

/* Copy() method */
Noeud* Ou::Copy() const{
return new Ou(Noeud1_->Copy(),Noeud2_->Copy());
}

/* GetNods method */
void Ou::GetNods(Noeud** tab,int* posit) {
  tab[*posit]=this;
  *posit = *posit+1;
  Noeud1_->GetNods(tab,posit);
  Noeud2_->GetNods(tab,posit);
}
