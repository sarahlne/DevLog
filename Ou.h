#ifndef OU_ 
#define OU_
#include"Noeud.h"
class Ou : public Noeud{

public:
Ou(Noeud*,Noeud*); 

bool Calcule(bool*) const override;
//Atributs
protected:
Noeud* Noeud1_;
Noeud* Noeud2_;

};
#endif //OU_