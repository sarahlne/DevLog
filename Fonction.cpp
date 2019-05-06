#include <iostream>
#include "Fonction.h"

#include "Noeud.h"
#include "Valeur.h"
#include "Variable.h"
#include "Ou.h"
#include "Et.h"
#include "Non.h"

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
}

//AdressFirstNode getter//
Noeud* Fonction::get_Adress(){
	return AdressFirstNode_;
}

// Calcul Methode //
bool Fonction::Calcul(bool input[]){
	return 1;
};


