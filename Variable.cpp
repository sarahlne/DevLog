#include"Variable.h"

Variable::Variable(unsigned u):posit_(u){
}

bool Variable::Calcule(bool* b) const{
return b[posit_];
}

std::string Variable::Affiche() const{

std::string s= std::to_string(posit_);
return  "X"+s;


}

void Variable::Unasigne(){
  delete this;
}

Noeud* Variable::Copy() const{
return new Variable(posit_);

}
void Variable::GetNods(Noeud** tab,int* posit){
  tab[*posit]=this;
  *posit = *posit+1;
}
