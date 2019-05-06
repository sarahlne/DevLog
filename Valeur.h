#ifndef VALEUR_ 
#define VALEUR_
#include"Noeud.h"
#include <string>
class Valeur : public Noeud{

public:
Valeur(bool); 

bool Calcule(bool*) const override;

std::string Affiche() const override;

void Unasigne() override;
//Atributs

protected:
bool val_;

};
#endif //VALEUR_
