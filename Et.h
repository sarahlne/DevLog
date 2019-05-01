#ifndef ET_ 
#define ET_
#include"Noeud.h"
class Et : public Noeud{

public:
Et(Noeud*,Noeud*); 

bool Calcule(bool*) const override;
//Atributs
protected:
Noeud* Noeud1_;
Noeud* Noeud2_;

};
#endif //ET_
