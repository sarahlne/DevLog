#include <iostream>
#include"Noeud.h"
#include"Valeur.h"
int main(){
std::cout << "Bonjour monde" << std::endl;

// test constructeur Valeur
Valeur Nf(false);
Valeur Nt(true);

Noeud* tabN[2];
tabN[0]=&Nf;
tabN[1]=&Nt;
bool a[2];
a[0]=true;
a[1]=false;
std::cout << tabN[0]->Calcule(a)<< std::endl;
std::cout << tabN[1]->Calcule(a)<< std::endl;
return 0;
}
