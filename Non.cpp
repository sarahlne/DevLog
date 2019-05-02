#include"Non.h"

Non::Non(Noeud* N1):Noeud1_(N1){
}
bool Non::Calcule(bool* b) const{
return not(Noeud1_->Calcule(b)) ;
}
