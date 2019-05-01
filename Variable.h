#ifndef VARIABLE_ 
#define VARIABLE_
#include"Noeud.h"
class Variable : public Noeud{

public:
Variable(unsigned); 

bool Calcule(bool*) const override;
//Atributs
protected:
bool posit_;
};
#endif //VARIABLE_
