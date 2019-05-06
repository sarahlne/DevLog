#include<iostream>
#include "Fonction.h"
#include "Noeud.h"
#ifndef SOLVE
#define SOLVE
class Solve{
  public:
    //Constructeur
    Solve();
    Solve(int dim , int nbfille);
    
    //destructeur
    ~Solve();
        
    //Function
    void evolve();
    
  
    //Getters
    
    
    
    
  protected:
    Fonction ** popFonct_   ; // tableau de fonction 
    //int  HistoricFitness_ [];
    int nbGeneration_;
    bool ** x_  ;
    bool * y_  ;
    int lambda_ ; //nombre d'enfants crée à chaque génération
    int nbvar_; // nombre de variables , ex (x1,x2,x3) nbvar=3
    
};

//Getter



#endif

