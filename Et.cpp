#include"Et.h"
/* Constructor */
Et::Et(Noeud* N1,Noeud* N2){
Noeud1_=N1;
Noeud2_=N2;
}

/*Calcul method */
bool Et::Calcule(bool* b) const{
return Noeud1_->Calcule(b) and Noeud2_->Calcule(b);
}

/*Affiche() method */
std::string Et::Affiche() const{
return  "("+Noeud1_->Affiche() +" And "+ Noeud2_->Affiche()+")";
}

/* Destructor */
void Et::Unasigne(){
  Noeud1_->Unasigne();
  Noeud2_->Unasigne();
  delete this;
}
/* Copy() method */
Noeud* Et::Copy() const{
return new Et(Noeud1_->Copy(),Noeud2_->Copy());
}

/* GetNods method */
void Et::GetNods(Noeud** tab,int* posit) {
  tab[*posit]=this;
  *posit = *posit+1;
  Noeud1_->GetNods(tab,posit);
  Noeud2_->GetNods(tab,posit);
}
