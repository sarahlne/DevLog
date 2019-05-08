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

Noeud* Copy() const override;

void GetNods(Noeud**,int*) override;
//Atributs
protected:

};
#endif //NON_
