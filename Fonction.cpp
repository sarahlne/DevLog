#include <iostream>
#include <string>

#include "Fonction.h"

using std::cout;
using std::cin;
using std::endl;

//Constructor//
Fonction::Fonction(Noeud* noeud){
	AdressFirstNode_ = noeud;
  len_=1;
  maxlen_=100;
  Nodes_=new Noeud*[100];
  Nodes_[0]=AdressFirstNode_;
  
}

//Copy constructor//
Fonction::Fonction(const Fonction& model){
	AdressFirstNode_ = model.AdressFirstNode_->Copy();
  len_= model.len_;
  maxlen_=100;
  int posit=0;
  AdressFirstNode_->GetNods(Nodes_,&posit);
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


