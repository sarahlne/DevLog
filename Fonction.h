#ifndef FONCTION_
#define FONCTION_ 
#include "Noeud.h"
#include "Valeur.h"
#include "Variable.h"
#include "Ou.h"
#include "Et.h"
#include "Non.h"

class Fonction{
	public:
	Fonction() = delete;
	/* Constructor */
	Fonction(Noeud* noeud);
	
	/* Copy constructor */
	Fonction(const Fonction& model);
	
	/* Destructor */
	~Fonction();
	
	/* toString() function */
	void toString();
	
	/* AdressFirstNode getter */
	Noeud* get_Adress();
	
	protected:
	
	private:
	Noeud* AdressFirstNode_;
	
};
#endif //CHARACTER_
