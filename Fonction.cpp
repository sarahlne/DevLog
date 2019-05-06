#include <iostream>
#include <string>

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
	AdressFirstNode_ = model.AdressFirstNode_->Copy();
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
bool Fonction::Calcule(bool input[]){
	return AdressFirstNode_->Calcule(input);
}

// Affiche() method //
std::string Fonction::Affiche(){
	return AdressFirstNode_->Affiche();
}


