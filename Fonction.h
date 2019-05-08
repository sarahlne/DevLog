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

#include <cstdlib>
#include <ctime>
#include <random>




extern int SIZE1;
extern int SIZE2;
class Fonction{
	public:
	Fonction() = delete;
	/* Constructor */
	Fonction(Noeud* noeud,int);
	
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

  /*Deleltion methode
provoque une deletion du noeud suivant le noeud à la position posit, si c'est possible.
renvoi True si la deletion s'est faite, False sinon*/
 
  bool Deletion(int posit);

  /*Insertion methode
provoque une insertion d'un noeud (copie) après le noeud à la position posit(si -1 ainsertion en tête) si c'est possible.
renvoi True si l'insertion s'est faite, False sinon*/
 
  bool Insertion(int posit,const Noeud*);


  /*EchangeN1N2(posit)
provoque l'échange de Noeud1_ et Noeud2_ à la position posit si c'est possible.(Un grand nombre de methode agissent sur Noeud1_ et non Noeud2_, concrètement cette methode permet d'établir une équivalence entre Noeud1_ et Noeud2_ dans la façon dont il seront ciblé par les methodes)
renvoi True si l'échange s'est fait, False sinon*/
  bool EchangeN1N2(int posit);

  /*Remplace(int posit,const Noeud*)
remplace le noeud par le noeud en parametre(copie) après le noeud à la position posit(si -1 ainsertion en tête) si c'est possible.
renvoi True si l'insertion s'est faite, False sinon*/
  bool Remplace(int posit,const Noeud*);

  /*Mute(int MutNumber)
effectue (si elle est possibles) une transformation de type Remplace, Echange, Insertion ou Deletion sur des noeuds aléatoire de la fonction */
  void Mute();
	
	/* CalculeFitness() method */
	float CalculeFitness(bool** input[3][2], bool expect_results[]);

  float Fitness(bool** ,int range, bool *);  
	
	protected:
	
	private:
	Noeud* AdressFirstNode_;
  Noeud** Nodes_;
  size_t len_;
  size_t maxlen_;
  int Nombre_Var_;
	
};
#endif //CHARACTER_
