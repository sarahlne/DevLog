#include <iostream>
#include"Noeud.h"
#include"Valeur.h"
#include"Variable.h"
#include"Ou.h"
int main(){
std::cout << "Bonjour monde" << std::endl;

// test constructeur Valeur
Valeur Nf(false);
Valeur Nt(true);
// test constructeur Variable
Variable V1(0);
Variable V2(1);

// test constructeur Ou

Ou O1(&Nf, &Nt);
Ou O2(&Nt, &V1);
Ou O3(&V1, &V2);
Ou O4(&V2, &Nf);

//test Calcule
Noeud* tabN[8];
tabN[0]=&Nf;
tabN[1]=&Nt;
tabN[2]=&V1;
tabN[3]=&V2;
tabN[4]=&O1;
tabN[5]=&O2;
tabN[6]=&O3;
tabN[7]=&O4;
bool X[2];
X[0]=true;
X[1]=false;
std::cout << (tabN[0]->Calcule(X)==false)<< std::endl;
std::cout << (tabN[1]->Calcule(X)==true)<< std::endl;
std::cout << (tabN[1]->Calcule(X)==true)<< std::endl;
std::cout << (tabN[3]->Calcule(X)==false)<< std::endl;
std::cout << (tabN[4]->Calcule(X)==true)<< std::endl;
std::cout << (tabN[5]->Calcule(X)==true)<< std::endl;
std::cout << (tabN[6]->Calcule(X)==true)<< std::endl;
std::cout << (tabN[7]->Calcule(X)==false)<< std::endl;
return 0;
}
