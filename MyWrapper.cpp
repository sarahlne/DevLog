#include <Python.h> //include the "Python.h" header before any other include
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <zlib.h>
#include <errno.h>
#include<iostream>
#include "def_PyC.h"
#include "Solve.h"

// Name for the cpp object "capsules"
#define NAME_CAPSULE_SOLVE "SOLVE"

//Receives a Python capsule for object A, and extracts the pointer of the C++ object
//Pyobjet : onejt du Python.h
static Solve* SolvePythonToC(PyObject* args){
	Solve* my_Solve;
	PyObject* capsule;
	if (!PyArg_ParseTuple(args, "O", &capsule)){
		return NULL;
	}
	my_Solve = (Solve*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_SOLVE);
	return my_Solve;
}
//si on a un autre objet faire une autre methode objetPython to C , un autre destructuer, une autre fonction Print ...

// Frees object A Python capsule
void SolveCapsuleDestructor(PyObject* capsule){
	Solve* my_solve = (Solve*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_SOLVE);

  delete my_solve;
}


// Calls the Print function of object A

static PyObject* PrintSolve(PyObject* self, PyObject* args){
    Solve*  my_Solve = SolvePythonToC(args);
    //std::cout<<"je suis dans le print"<<std::endl;
    my_Solve->affiche_final_fonction();
    //renvoie un None de Python
    //Incremente , a chaque fois qu'il est creer , on incremente
    // 2 lignes pas forcement utile
    //renvoie une nouvelle instance de None , donc il faut incrémenter
    // mettre ces lignes si on fait des returns de None
    Py_INCREF(Py_None);
    return Py_None;
}


// Receive and parse parameters, constructs an object Solve, encapsulate it and return the capsule
//self : librairie  , args : objet python , les arguments donnés
static PyObject* SolveTranslator(PyObject* self, PyObject* args){
	int lambda;
	PyListObject* Xobj;
	PyListObject* Yobj;
	int generations;
	if (!PyArg_ParseTuple(args, "hOOh", &lambda, &Xobj, &Yobj, &generations)){
	//parse un tuple
	//tuple des arguments , args 
	//"h" : type des éléments de args , EX: si 2 int : "hh"  , si objet pyhton comme liste "O" , (args , "hO" , &a , &obj)
	//&a l'element en c++ ou on va mettre le contenu (les args)
	//le if teste les arguments rentrées , si il ne sont pas bons --> NULL , ne focntionne pas
		return NULL;
	}
	int rangeX=PyList_Size((PyObject*)Xobj);
	int dim=PyList_Size((PyObject*) ((PyObject*) PyList_GetItem( (PyObject*) Xobj, (Py_ssize_t) 0)));
	bool ** X=new bool* [rangeX];
	bool * Y=new bool [rangeX];
	
    for (int i = 0; i <rangeX; i++){
    		bool * x=new bool [dim];
        PyObject* ligne_de_X = (PyObject*) PyList_GetItem( (PyObject*) Xobj, (Py_ssize_t) i); 
        for (int j=0 ; j<dim ; j++){
        	  x[j]=bool(PyLong_AsLong((PyObject*) PyList_GetItem( (PyObject*)ligne_de_X, (Py_ssize_t) j)));
        }
        Y[i]= bool(PyLong_AsLong((PyObject*) PyList_GetItem( (PyObject*) Yobj, (Py_ssize_t) i)));
        X[i]=x;
    }
	//initialiser tableau vide
	//double boucle , remplir les valeurs
	//transformer int python en int c++ 
	std::cout<<"je suis avant le constructeur"<<std::endl;
	Solve* my_Solve = new Solve(dim,lambda, X,rangeX,Y, generations);
	PyObject* capsule = PyCapsule_New(my_Solve, NAME_CAPSULE_SOLVE, SolveCapsuleDestructor);
	std::cout<<"je suis apres la capsule"<<std::endl;
	//creer la capsule 
	//Py capsule : du Python .h 
	//arguments : l'objet- pointeur c++, nom Capsule ( du #define au début) , le destructeur pour vider la capsule
	return capsule;
}


/*static PyObject* SumAsInPyList(PyObject* self, PyObject* args){
    PyListObject* listOfAs;
    int a = 0;
    if (!PyArg_ParseTuple(args, "Ohh", &listOfAs)){
        return NULL;
    }
    int size = PyList_Size((PyObject*) listOfAs);
    for (int i = 0; i < size; i++){
        PyObject* capsule = (PyObject*) PyList_GetItem( (PyObject*) listOfAs, (Py_ssize_t) i);
        A* my_A = (A*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_A);
        a += my_A->a;
    }
    A* my_A = new A(a);
  	PyObject* capsule = PyCapsule_New(my_A, NAME_CAPSULE_A, ACapsuleDestructor);
  	return Py_BuildValue("Oi",capsule,a);
}
*/


// Module functions {<python function name>, <function in wrapper>, <parameters flag>, <doctring>}
// https://docs.python.org/3/c-api/structures.html
static PyMethodDef module_funcs[] = {
//4 trucs pour chaque methode : le nom de la fontion Python, nom de la methode en c++, type d'arguments ( laisser le METH_varrags , prends des arguments , puis la docstring
// (PycFunction) pour dire à Pyhton , que c'est une capsule , à voir si c'est utile
    {"create_solver", (PyCFunction)SolveTranslator, METH_VARARGS, "Create an instance of class Solve\n\nArgs:\n\t int dim the dimension of vectors that the Fonctions will take \n\t int nbfille numbers of new Fonctions created at each generation \n\nReturns:\n\t capsule: Object Solve capsule"},
    /*{"sum_list_As", (PyCFunction)SumAsInPyList, METH_VARARGS, "Sum the As in a list\n\nArgs:\n\tlist_As (list): list of capsules A\n\nReturns:\n\t Capsules: Object A capsule\n\t int: sum of A's a"},*/
    {"print_fonct", (PyCFunction)PrintSolve, METH_VARARGS,  "Print class Solve instance\n\n Args:\n\t capsuleA (Capsule) : object A capsule \n\n Print the final Function find by the solver"},
		{NULL, NULL, METH_NOARGS, NULL} // no args : ne prends pas d'arguments
};

static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "BinSymReg",
        "BinSymReg is a library for Binary symbolic Regression",
        //taille du module
        sizeof(PyObject*),
        //toutes les focntions: 
				module_funcs,
				NULL,
        NULL,
        NULL,
        NULL
};

PyMODINIT_FUNC PyInit_BinSymReg(void){
    PyObject* module = PyModule_Create(&moduledef);
		return module;
}
