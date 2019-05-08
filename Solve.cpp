#include "Solve.h"
#include<iostream>



//##################CONSTRUCTORS and DESTRUCTORS ##################

// Constructeur par défaut
Solve::Solve(){
  lambda_=5;
  nbvar_=3;
  popFonct_ = (Fonction**) malloc(lambda_*sizeof(Fonction*));
  popFonct_[0]=new Fonction(new Valeur(true));
  //il faut initialiser les cases de popFonct_
  for (int i=1; i<lambda_; i++){
    popFonct_[i]=NULL;
  }
  //HistoricFitness_[0]=new int(popFonct_[0].fitness());
}

Solve::Solve(int dim , int nbfille){
  lambda_= nbfille;
  nbvar_= dim;
  popFonct_ = (Fonction**) malloc(lambda_*sizeof(Fonction*));
  popFonct_[0]=new Fonction(new Valeur(true));
  //il faut initialiser les cases de popFonct_
  for (int i=1; i<lambda_; i++){
    popFonct_[i]=NULL;
  }
  //HistoricFitness_[0]=new int(popFonct_[0].fitness());
}

//destructeur
Solve::~Solve(){
  for(int i=0; i<lambda_; i++){ //delete chaque pointeur de tableau
    //vérifie que  le pointeur n'est pas nulle , c'est à dire , si il y a une valeur on le supprime
    //faire ça a chaque fois qu'on supprimer les éléments de popFunction
    if (popFonct_[i]){
      delete popFonct_[i];
    }
  } 
  free(popFonct_) ; 
}

//##################FUNCTIONS##################

int Solve::bestFitness(int * HistoricFitness_){//return l'emplacement de la meilleur fitness du tableau
  int place;
  for(int i=0; i<lambda_;++i){
    int best = HistoricFitness_[0];
    
    if(HistoricFitness_[i]>best){
      best=HistoricFitness_[i];
      place=i;
    }
  }
  return place;
}

void Solve::ReplaceFitness(int place){
  HistoricFitness_[0]=HistoricFitness_[place]; 
}

Fonction * Solve::bestFct(Fonction ** popFonct_,int place){//return le meilleure fonction
  return popFonct_[place];
}

void Solve::PlacementFct(int place ){//Met la meilleure fonction en premier rang

  Fonction* f1 = bestFct(popFonct_,place);
  
  for(int i=0;i<lambda_;++i){
    if (popFonct_[i]){
      delete popFonct_[i];
    }
  }
  
  popFonct_[0]=f1;
}


void Solve::evolve(int nbGeneration,Fonction ** popFonct_,int * HistoricFitness_){

  for(int i=0;i<nbGeneration_;++i){
    for(int i=1; i< lambda_;i++){
  
      //popFonct_[i]=popFonct_[0]->mute();
      //HistoricFitness_[i]=popFonct_[i]->fitness();
    }
    int place =bestFitness( HistoricFitness_);
    ReplaceFitness(place);
    PlacementFct(place);  
    
  }
}

void Solve::affiche_final_fonction()const{
	std::cout<<popFonct_[0]->Affiche()<<std::endl;
}
