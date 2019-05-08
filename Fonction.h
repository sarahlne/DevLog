#ifndef FONCTION_
#define FONCTION_ 
#include <iostream>
#include <string>

#include"Noeud.h"
#include"Valeur.h"
#include"Variable.h"
#include"Ou.h"
#include"Et.h"
#include"Non.h"

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

  /*Deleltion methode
provoque une deletion du noeud suivant le noeud à la position posit, si c'est possible.
renvoi True si la deletion s'est faite, False sinon*/
 
  bool Deletion(int posit);

  /*Insertion methode
provoque une insertion d'un noeud après le noeud à la position posit(si -1 avant le premier noeud) si c'est possible.
renvoi True si la deletion s'est faite, False sinon*/
 
  bool Insertion(int ,const Noeud*);
	
	protected:
	
	private:
	Noeud* AdressFirstNode_;
  Noeud** Nodes_;
  size_t len_;
  size_t maxlen_;
	
};
#endif //CHARACTER_
