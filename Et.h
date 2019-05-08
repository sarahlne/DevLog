#ifndef ET_ 
#define ET_
#include"Noeud.h"
#include <string>
class Et : public Noeud{

public:
Et(Noeud*,Noeud*);

bool Calcule(bool*) const override;

std::string Affiche() const override;

void Unasigne() override;

Noeud* Copy() const override;

void GetNods(Noeud**,int*)  override;
//Atributs
protected:
Noeud* Noeud2_;

};
#endif //ET_
