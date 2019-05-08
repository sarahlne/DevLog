#include"Non.h"

Non::Non(Noeud* N1){
Noeud1_=N1;
}
bool Non::Calcule(bool* b) const{
return not(Noeud1_->Calcule(b)) ;
}


std::string Non::Affiche() const{

return  "Not ("+ Noeud1_->Affiche() +")";


}

void Non::Unasigne(){
  Noeud1_->Unasigne();
  delete this;
}

Noeud* Non::Copy() const{
return new Non(Noeud1_->Copy());

}
void Non::GetNods(Noeud** tab,int* posit) {
  tab[*posit]=this;
  *posit = *posit+1;
  Noeud1_->GetNods(tab,posit);
}
