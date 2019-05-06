#include<iostream>
#include "Fonction.h"
#ifndef SOLVE
#define SOLVE
class Solve{

  public:
    //Constructeur
    Solve();
    
        
    //Function
    virtual void evoluer();
    
  
    //Getters
    
    
    
    
  protected:
  
    Fonction [] popFonction; // tableau de fonction 
    int [] HistoricFitness;
    
};

//Getter

  

}


#endif

