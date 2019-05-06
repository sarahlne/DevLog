CXXFLAGS= -Wall -O0 -g



main: main.o Noeud.o Fonction.o Valeur.o Variable.o Ou.o Et.o Non.o  Solve.o
	g++ -o main main.o Fonction.o Noeud.o Valeur.o Variable.o Ou.o Et.o Non.o Solve.o

main.o: main.cpp
	g++ -o main.o -c ${CXXFLAGS} main.cpp

Noeud.o: Noeud.cpp Noeud.h
	g++ -o Noeud.o -c ${CXXFLAGS} Noeud.cpp

Fonction.o: Fonction.cpp Fonction.h
	g++  -o Fonction.o -c ${CXXFLAGS} Fonction.cpp

Valeur.o: Valeur.cpp Valeur.h
	g++ -o Valeur.o -c ${CXXFLAGS} Valeur.cpp

Variable.o: Variable.cpp Variable.h
	g++ -o Variable.o -c ${CXXFLAGS} Variable.cpp

Ou.o: Ou.cpp Ou.h
	g++ -o Ou.o -c ${CXXFLAGS} Ou.cpp

Et.o: Et.cpp Et.h
	g++ -o Et.o -c ${CXXFLAGS} Et.cpp

Non.o: Non.cpp Non.h
	g++ -o Non.o -c ${CXXFLAGS} Non.cpp
	
Solve.o : Solve.cpp  Solve.h
	g++  -o Solve.o -c ${CXXFLAGS} Solve.cpp

clean:
	rm main.o Valeur.o Noeud.o Variable.o Ou.o Et.o Non.o main Fonction.o Solve.o
leak:
	valgrind --leak-check=full ./main
