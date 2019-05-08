#ifndef FONCTION_
#define FONCTION_ 
#include <iostream>
#include <string>

#include "Noeud.h"
#include"Valeur.h"
#include"Variable.h"
#include"Ou.h"
#include"Et.h"
#include"Non.h"

int a = 3;
int b = 2;
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
	
	/* Calcul() method */
	bool Calcule(bool* input);
	
	/* Affiche() method() */
	std::string Affiche();
	
	/* CalculeFitness() method */
	float CalculeFitness(bool** input[3][2], bool expect_results[]); 
	
	protected:
	
	private:
	Noeud* AdressFirstNode_;
	
};
#endif //CHARACTER_
