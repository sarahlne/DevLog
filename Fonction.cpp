#include <iostream>
#include <string>

#include "Noeud.h"
#include"Valeur.h"
#include"Variable.h"
#include"Ou.h"
#include"Et.h"
#include"Non.h"
#include "Fonction.h"

using std::cout;
using std::cin;
using std::endl;

//Constructor//
Fonction::Fonction(Noeud* noeud){
	AdressFirstNode_ = noeud;
}

//Copy constructor//
Fonction::Fonction(const Fonction& model){
	AdressFirstNode_ = model.AdressFirstNode_;
}

//Destructor//
Fonction::~Fonction(){
  AdressFirstNode_->Unasigne();
}

//AdressFirstNode getter//
Noeud* Fonction::get_Adress(){
	return AdressFirstNode_;
}

// Calcul() method //
bool Fonction::Calcule(bool* input){
	return AdressFirstNode_->Calcule(input);
}

// Affiche() method //
std::string Fonction::Affiche(){
	return AdressFirstNode_->Affiche();
}
// CaluleFitness() method //
float Fonction::CalculeFitness(bool** input, int taille, bool* expect_results){
	float Fitness=0.0;
	for(int i = 0; i < taille; i++){
		if ((AdressFirstNode_->Calcule(input[i]))==expect_results[i]) {
			++Fitness;
		}
	}
	return Fitness;
}

