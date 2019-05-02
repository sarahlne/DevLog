#ifndef NON_ 
#define NON_
#include"Noeud.h"
class Non : public Noeud{

public:
Non(Noeud*); 

bool Calcule(bool*) const override;
//Atributs
protected:
Noeud* Noeud1_;

};
#endif //NON_
