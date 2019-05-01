#include"Ou.h"

Ou::Ou(Noeud* N1,Noeud* N2):Noeud1_(N1),Noeud2_(N2){
}
bool Ou::Calcule(bool* b) const{
return Noeud1_->Calcule(b) or Noeud2_->Calcule(b);
}
