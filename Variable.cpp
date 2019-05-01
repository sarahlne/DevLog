#include"Variable.h"

Variable::Variable(unsigned u):posit_(u){
}

bool Variable::Calcule(bool* b) const{
return b[posit_];
}
