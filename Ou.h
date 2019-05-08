#ifndef OU_ 
#define OU_
#include"Noeud.h"
#include <string>
class Ou : public Noeud{

public:
Ou(Noeud*,Noeud*); 

bool Calcule(bool*) const override;

std::string Affiche() const override;

void Unasigne() override;

Noeud* Copy() const override;

void GetNods(Noeud**,int*)  override;
//Atributs
protected:

};
#endif //OU_
