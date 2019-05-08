CXXFLAGS= -Wall -O0 -g

objects = main.o Noeud.o Fonction.o Valeur.o Variable.o Ou.o Et.o Non.o  Solve.o

all:main

main: $(objects)
	g++ -o main $(objects) $(CXXFLAGS)

main.o: main.cpp
Noeud.o: Noeud.cpp Noeud.h
Fonction.o: Fonction.cpp Fonction.h
Valeur.o: Valeur.cpp Valeur.h
Non.o: Non.cpp Non.h
Variable.o: Variable.cpp Variable.h
Solve.o : Solve.cpp  Solve.h
Ou.o: Ou.cpp Ou.h
Et.o: Et.cpp Et.h

%.o:%.cpp
	g++ -o $@ -c $< $(CXXFLAGS)

clean:
	rm $(objects) 
leak:
	valgrind --leak-check=full ./main
