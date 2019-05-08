#include <iostream>
#include <string>

#include "Fonction.h"

using std::cout;
using std::cin;
using std::endl;

//Constructor//
Fonction::Fonction(Noeud* noeud){
	AdressFirstNode_ = noeud;
  maxlen_=100;
  Nodes_=new Noeud*[100];
  int posit=0;
  AdressFirstNode_->GetNods(Nodes_,&posit);
  len_=posit;
  
}

//Copy constructor//
Fonction::Fonction(const Fonction& model){
	AdressFirstNode_ = model.AdressFirstNode_->Copy();
  len_= model.len_;
  maxlen_=100;
  int posit=0;
  Nodes_=new Noeud*[100];
  AdressFirstNode_->GetNods(Nodes_,&posit);
}

//Destructor// 
Fonction::~Fonction(){
  AdressFirstNode_->Unasigne();
  delete[] Nodes_;
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
//Deletion() methode//


bool Fonction::Deletion(int posit){
  if (posit == -1){ //cas ou l'on suprime le premier noeud
    if(AdressFirstNode_->Noeud1_!=nullptr){// on ne veux pas suprimer une variable
      Noeud* Nprov = AdressFirstNode_;// on sauvegarde l'adresse de la branche que l'on va suprimer
      AdressFirstNode_=AdressFirstNode_->Noeud1_->Copy();// on cré une nouvelle branche, copie de la branche actuelle avec un noeud en moins, on l'acroche à notre arbre à la place de la branche que l'on va suprimer
      Nprov->Unasigne();//On suprime l'ancienne branche
      int p=0;
      AdressFirstNode_->GetNods(Nodes_,&p); // on recré la liste des noeuds
      len_=p;
      return true;
    }
   return false;    
  }
  else{
    if(Nodes_[posit]->Noeud1_!=nullptr and  Nodes_[posit]->Noeud1_->Noeud1_!=nullptr){// Une variable n'a pas de noeud suivant et on ne veux pas suprimer une variable
      Noeud* Nprov = Nodes_[posit]->Noeud1_;
      Nodes_[posit]->Noeud1_=Nodes_[posit]->Noeud1_->Noeud1_->Copy();
      Nprov->Unasigne();
      int p=0;
      AdressFirstNode_->GetNods(Nodes_,&p);
      len_=p;
      return true;
    }
   return false;
  }
}
bool Fonction::Insertion(int posit,const Noeud* n){
  if(n->Noeud1_==nullptr){
    return false; //on ne peut pas insérer de valeur ou de variable (cela suprimerait le reste de la branche) 
  }
  Noeud* InsN= n->Copy(); 
  InsN->Noeud1_->Unasigne(); //on à créé une copie du Noeud à insérer auquel on à suprimé la branche ataché à son premier noeud.
  if (posit==-1){  
    InsN->Noeud1_=AdressFirstNode_;
    AdressFirstNode_=InsN; //On à insérer le noeud dans notre arbre
  }else{
    if(Nodes_[posit]->Noeud1_==nullptr){
      return false; //on ne peut pas insérer  après une variable ou une valeur (il n'y à alors plus de branche)
    }
    InsN->Noeud1_=Nodes_[posit]->Noeud1_;
    Nodes_[posit]->Noeud1_=InsN;//On à insérer le noeud dans notre arbre

  }
  int p=0;
  AdressFirstNode_->GetNods(Nodes_,&p); // on recré la liste des noeuds
  len_=p;// on recaclcule la taille de la fonction 
  return true;
}
bool Fonction::EchangeN1N2(int posit){
  if (Nodes_[posit]->Noeud1_== nullptr or Nodes_[posit]->Noeud2_== nullptr){
    return false;
  }
  Noeud * provisoir = Nodes_[posit]->Noeud1_;
  Nodes_[posit]->Noeud1_ =Nodes_[posit]->Noeud2_;
  Nodes_[posit]->Noeud2_ =provisoir;
  return true;

}

