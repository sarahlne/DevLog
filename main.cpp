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
#include <cstdlib>
#include <ctime>
int main(){
srand(time(NULL));
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

Fonction F1(Ecopy2,2);
std::cout << (F1.Affiche()) << std::endl;

Solve S1();
//std::cout << "\n affichage du solveur 1 \n " << S1.affiche_final_fonction() << std::endl;


std::cout <<"Test Deletion"<< std::endl;
Fonction* F2= new Fonction(F1);

std::cout << (F2->Affiche()) << std::endl;

F2->Deletion(-1);

std::cout << (F2->Affiche()) << std::endl;

F2->Deletion(-1);

std::cout << (F2->Affiche()) << std::endl;

F2->Deletion(-1);

std::cout << (F2->Affiche()) << std::endl;

Fonction* F3= new Fonction(F1);

F3->Deletion(0);

std::cout << (F3->Affiche()) << std::endl;

std::cout <<"Test Insertion"<< std::endl;

std::cout <<(O2.Affiche())+" insert in head of "+ (F2->Affiche()) << std::endl;

F2->Insertion(-1,&O2);

std::cout <<" result: "+ (F2->Affiche()) << std::endl;

std::cout << (E3.Affiche())+" insert in head of"+ (F2->Affiche()) << std::endl;

F2->Insertion(-1,&E3);

std::cout <<" result: "+ (F2->Affiche()) << std::endl;

std::cout << (N1.Affiche())+" insert in head of"+ (F2->Affiche()) << std::endl;

F2->Insertion(-1,&N1);

std::cout <<" result: "+ (F2->Affiche()) << std::endl;

std::cout << (E1.Affiche())+" insert after head of "+ (F2->Affiche()) << std::endl;

F2->Insertion(0,&E1);

std::cout <<" result: "+ (F2->Affiche()) << std::endl;

std::cout <<"Test EchangeN1N2"<< std::endl;

F2->Deletion(-1);

std::cout << "EchangeN1N2 order of first node in "+ (F2->Affiche()) << std::endl;

F2->EchangeN1N2(0);

std::cout <<" result: "+ (F2->Affiche()) << std::endl;

std::cout << "EchangeN1N2 order of ((True Or X0) And X1) in "+ (F2->Affiche()) << std::endl;

F2->EchangeN1N2(1);

std::cout <<" result: "+ (F2->Affiche()) << std::endl;

std::cout <<"Test Remplace"<< std::endl;




std::cout << (E1.Affiche())+" remplace  head of : "+ (F2->Affiche()) << std::endl;

F2->Remplace(-1,&E1);

std::cout <<" result: "+ (F2->Affiche()) << std::endl;

std::cout << (O3.Affiche())+" remplace  head of : "+ (F2->Affiche()) << std::endl;

F2->Remplace(-1,&O3);

std::cout <<" result: "+ (F2->Affiche()) << std::endl;

std::cout << (N1.Affiche())+" remplace  head of : "+ (F2->Affiche()) << std::endl;

F2->Remplace(-1,&N1);

std::cout <<" result: "+ (F2->Affiche()) << std::endl;

std::cout << (V1.Affiche())+" remplace  True in : "+ (F2->Affiche()) << std::endl;

F2->Remplace(0,&V1);

std::cout <<" result: "+ (F2->Affiche()) << std::endl;

for(int i=0;i<10;i++){
  F2->Mute();
  std::cout <<" Mutate: "+ (F2->Affiche()) << std::endl;
}

delete F2;
delete F3;
delete Esup;
return 0;
}
