#ifndef FONCTION_
#define FONCTION_ 
#include <iostream>
#include <string>

#include "Noeud.h"


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
	
	/* Calcul methode */
	bool Calcule(bool input[]);
	
	/* Affiche method() */
	std::string Affiche();
	
	protected:
	
	private:
	Noeud* AdressFirstNode_;
  Noeud** Nodes_;
  size_t len_;
  size_t maxlen_;
	
};
#endif //CHARACTER_
