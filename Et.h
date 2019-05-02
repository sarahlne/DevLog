#ifndef ET_ 
#define ET_
#include"Noeud.h"
#include <string>
class Et : public Noeud{

public:
Et(Noeud*,Noeud*); 

bool Calcule(bool*) const override;

std::string Affiche() const override;
//Atributs
protected:
Noeud* Noeud1_;
Noeud* Noeud2_;

};
#endif //ET_
