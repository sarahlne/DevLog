#include"Ou.h"

Ou::Ou(Noeud* N1,Noeud* N2):Noeud1_(N1),Noeud2_(N2){
}
bool Ou::Calcule(bool* b) const{
return Noeud1_->Calcule(b) or Noeud2_->Calcule(b);
}

std::string Ou::Affiche() const{

return  "("+Noeud1_->Affiche() +" Or "+ Noeud2_->Affiche()+")";


}

void Ou::Unasigne(){
  Noeud1_->Unasigne();
  Noeud2_->Unasigne();
  delete this;
}

Noeud* Ou::Copy() const{
return new Ou(Noeud1_->Copy(),Noeud2_->Copy());

}
void Ou::GetNods(Noeud** tab,int* posit) {
  tab[*posit]=this;
  posit ++;
  Noeud1_->GetNods(tab,posit);
  Noeud2_->GetNods(tab,posit);
}
