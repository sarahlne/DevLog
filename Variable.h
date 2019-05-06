#ifndef VARIABLE_ 
#define VARIABLE_
#include"Noeud.h"
#include <string>
class Variable : public Noeud{

public:
Variable(unsigned); 

bool Calcule(bool*) const override;

std::string Affiche() const override;

void Unasigne()  override;
//Atributs
protected:
bool posit_;
};
#endif //VARIABLE_
