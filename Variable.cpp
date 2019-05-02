#include"Variable.h"

Variable::Variable(unsigned u):posit_(u){
}

bool Variable::Calcule(bool* b) const{
return b[posit_];
}

std::string Variable::Affiche() const{

std::string r("X");
std::string l= std::to_string(posit_);
return  r+l;


}
