#ifndef NODE_ 
#define NODE_
#include <string>

class Noeud{

public:
virtual bool Calcule(bool*) const=0;

virtual std::string Affiche() const;
};
#endif //NODE_
