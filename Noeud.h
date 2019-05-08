#ifndef NODE_ 
#define NODE_
#include <string>

class Noeud{

public:
virtual bool Calcule(bool*) const=0;

virtual std::string Affiche() const;


virtual void Unasigne() =0;

virtual Noeud* Copy() const =0;

virtual void GetNods(Noeud**,int*)  =0;

protected:
Noeud* Noeud1_=nullptr;


};
#endif //NODE_
