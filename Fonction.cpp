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
	Fitness_ = 0.0;
}

//Copy constructor//
Fonction::Fonction(const Fonction& model){
	AdressFirstNode_ = model.AdressFirstNode_;
	Fitness_ = model.Fitness_;
}

//Destructor//
Fonction::~Fonction(){
  AdressFirstNode_->Unasigne();
}

//AdressFirstNode getter//
Noeud* Fonction::get_Adress(){
	return AdressFirstNode_;
}

//Fitness getter//
 float Fonction::get_Fitness(){
 	return Fitness_;
 }


