#include"Non.h"
/* Constructor */
Non::Non(Noeud* N1){
Noeud1_=N1;
}

/*Calcul method */
bool Non::Calcule(bool* b) const{
return not(Noeud1_->Calcule(b)) ;
}

/*Affiche() method */
std::string Non::Affiche() const{
return  "Not ("+ Noeud1_->Affiche() +")";
}

/* Destructor */
void Non::Unasigne(){
  Noeud1_->Unasigne();
  delete this;
}

/* Copy() method */
Noeud* Non::Copy() const{
return new Non(Noeud1_->Copy());
}

/* GetNods method */
void Non::GetNods(Noeud** tab,int* posit) {
  tab[*posit]=this;
  *posit = *posit+1;
  Noeud1_->GetNods(tab,posit);
}
