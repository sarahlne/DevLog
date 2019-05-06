#include "Solve.h"



//##################CONSTRUCTORS and DESTRUCTORS ##################

// Constructeur par défaut
Solve::Solve(){
  lambda_=5;
  nbvar_=3;
  popFonct_= new Fonction[lambda_];
  noeud1=new Valeur(True);
  popFonct_[0]=new Fonction(noeud1);
}

Solve::Solve(int dim , int nbfille){
  lambda_=nbfille;
  nbvar_=dim;
  popFonct_= new Fonction[lambda_];
  noeud1=new Valeur(True);
  popFonct_[0]=new Fonction(noeud1);
}
//destructeur
Solve:~Solve(){
  delete [] popFonct ;
  
}

//##################FUNCTIONS##################

void Solve::evolve(){

}
