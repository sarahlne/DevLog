#ifndef NON_ 
#define NON_
#include"Noeud.h"
#include <string>
class Non : public Noeud{

public:
Non(Noeud*); 

bool Calcule(bool*) const override;

std::string Affiche() const override;

void Unasigne()  override;
//Atributs
protected:
Noeud* Noeud1_;

};
#endif //NON_
