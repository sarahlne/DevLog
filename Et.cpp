#include"Et.h"

Et::Et(Noeud* N1,Noeud* N2):Noeud1_(N1),Noeud2_(N2){
}
bool Et::Calcule(bool* b) const{
return Noeud1_->Calcule(b) and Noeud2_->Calcule(b);
}

std::string Et::Affiche() const{

return  "("+Noeud1_->Affiche() +" And "+ Noeud2_->Affiche()+")";


}

void Et::Unasigne(){
  Noeud1_->Unasigne();
  Noeud2_->Unasigne();
  delete this;
  
}
