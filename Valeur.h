#ifndef VALEUR_ 
#define VALEUR_
#include"Noeud.h"
class Valeur : public Noeud{

public:
Valeur(bool); 

bool Calcule(bool*) const override;
//Atributs
protected:
bool val_;
};
#endif //VALEUR_
