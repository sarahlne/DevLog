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
	
	/* Fitness getter */
	float get_Fitness();
	
	protected:
	
	private:
	Noeud* AdressFirstNode_;
	float Fitness_;
	
};
#endif //CHARACTER_
