#include "Solve.h"



//##################CONSTRUCTORS and DESTRUCTORS ##################

// Constructeur par défaut
Solve::Solve(){
  lambda_=5;
  nbvar_=3;
  popFonct_ = (Fonction**) malloc(lambda_*sizeof(Fonction*));
  Valeur noeud1(true);
  popFonct_[0]=new Fonction(&noeud1);
}

Solve::Solve(int dim , int nbfille){
  lambda_=nbfille;
  nbvar_=dim;
  popFonct_ = (Fonction**) malloc(lambda_*sizeof(Fonction*));
  Valeur noeud1(true);
  popFonct_[0]=new Fonction(&noeud1);
}
//destructeur
Solve::~Solve(){
  for(int i; i<lambda_; i++){ //delete chaque pointeur de tableau
    delete popFonct_[i];
  } 
  free(popFonct_) ;
  
}

//##################FUNCTIONS##################




void Solve::evolve(){

}


void Solve::affiche_final_fonction(){
	popFonct_[0]->Affiche();
}
