#include <iostream>
#include <string>

#include"Noeud.h"
#include"Valeur.h"
#include"Variable.h"
#include"Ou.h"
#include"Et.h"
#include"Non.h"
#include"Fonction.h"
#include"Solve.h"

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

// test constructeur Et

Et E1(&Nf, &Nt);
Et E2(&Nt, &V1);
Et E3(&V1, &V2);
Et E4(&V2, &Nf);

// test constructeur Non

Non N1(&Nt);
Non N2(&Nf);

//test Calcule
Noeud* tabN[14];
tabN[0]=&Nf;
tabN[1]=&Nt;
tabN[2]=&V1;
tabN[3]=&V2;
tabN[4]=&O1;
tabN[5]=&O2;
tabN[6]=&O3;
tabN[7]=&O4;
tabN[8]=&E1;
tabN[9]=&E2;
tabN[10]=&E3;
tabN[11]=&E4;
tabN[12]=&N1;
tabN[13]=&N2;
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
std::cout << (tabN[8]->Calcule(X)==false)<< std::endl;
std::cout << (tabN[9]->Calcule(X)==true)<< std::endl;
std::cout << (tabN[10]->Calcule(X)==false)<< std::endl;
std::cout << (tabN[11]->Calcule(X)==false)<< std::endl;
std::cout << (tabN[12]->Calcule(X)==false)<< std::endl;
std::cout << (tabN[13]->Calcule(X)==true)<< std::endl;
// test affichage
std::cout << (tabN[0]->Affiche())<< std::endl;
std::cout << (tabN[1]->Affiche())<< std::endl;
std::cout << (tabN[2]->Affiche())<< std::endl;
std::cout << (tabN[3]->Affiche())<< std::endl;

std::cout << (tabN[4]->Affiche())<< std::endl;
std::cout << (tabN[5]->Affiche())<< std::endl;
std::cout << (tabN[6]->Affiche())<< std::endl;
std::cout << (tabN[7]->Affiche())<< std::endl;

std::cout << (tabN[8]->Affiche())<< std::endl;
std::cout << (tabN[9]->Affiche())<< std::endl;
std::cout << (tabN[10]->Affiche())<< std::endl;
std::cout << (tabN[11]->Affiche())<< std::endl;

std::cout << (tabN[12]->Affiche())<< std::endl;
std::cout << (tabN[13]->Affiche())<< std::endl;

Ou Osup(&O2,&E1);
Non Nsup(&E3);
Et* Esup=new Et(&Osup, &Nsup);

std::cout << (Esup->Affiche())<< std::endl;
std::cout << (Esup->Calcule(X))<< std::endl;

Noeud* Ecopy1=Esup->Copy();
Noeud* Ecopy2=Ecopy1->Copy();

std::cout << (Ecopy1->Affiche())<< std::endl;
std::cout << (Ecopy1->Calcule(X))<< std::endl;

Ecopy1->Unasigne();

std::cout << (Ecopy2->Affiche())<< std::endl;
std::cout << (Ecopy2->Calcule(X))<< std::endl;

Fonction F1(Ecopy2);
std::cout << (F1.Affiche()) << std::endl;


Solve s11;  //genere un seg fault
std::cout << "\n affichage du solveur 1 : \n " ;
s11.affiche_final_fonction() ;
//Solve s12;
//std::cout << "\n affichage du solveur 2 : \n " ;
//s12.affiche_final_fonction() ; 

Fonction* F2= new Fonction(F1);

std::cout << (F2->Affiche()) << std::endl;
//on ne peut pas appeler le delete sur F2 et Esup car pas de destructeur
delete F2;
delete Esup;


return 0;
}
