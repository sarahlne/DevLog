#ifndef NODE_ 
#define NODE_
#include <string>

class Noeud{

public:
virtual bool Calcule(bool*) const=0;

virtual std::string Affiche(bool*) const;
};
#endif //NODE_
