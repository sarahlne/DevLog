#include <iostream>
#include"Noeud.h"
#include"Valeur.h"
#include"Variable.h"
int main(){
std::cout << "Bonjour monde" << std::endl;

// test constructeur Valeur
Valeur Nf(false);
Valeur Nt(true);
// test constructeur Variable
Variable V1(0);
Variable V2(1);

//test Calcule
Noeud* tabN[4];
tabN[0]=&Nf;
tabN[1]=&Nt;
tabN[2]=&V1;
tabN[3]=&V2;
bool X[2];
X[0]=true;
X[1]=false;
std::cout << tabN[0]->Calcule(X)<< std::endl;
std::cout << tabN[1]->Calcule(X)<< std::endl;
std::cout << tabN[1]->Calcule(X)<< std::endl;
std::cout << tabN[3]->Calcule(X)<< std::endl;
return 0;
}
