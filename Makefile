CXXFLAGS= -Wall -O0 -g


main: main.o Noeud.o Valeur.o Variable.o Ou.o
	g++ -o main main.o Noeud.o Valeur.o Variable.o Ou.o

main.o: main.cpp
	g++ -o main.o -c ${CXXFLAGS} main.cpp

Noeud.o: Noeud.cpp Noeud.h
	g++ -o Noeud.o -c ${CXXFLAGS} Noeud.cpp

Valeur.o: Valeur.cpp Valeur.h
	g++ -o Valeur.o -c ${CXXFLAGS} Valeur.cpp

Variable.o: Variable.cpp Variable.h
	g++ -o Variable.o -c ${CXXFLAGS} Variable.cpp

Ou.o: Ou.cpp Ou.h
	g++ -o Ou.o -c ${CXXFLAGS} Ou.cpp

clean:
	rm main.o Valeur.o Noeud.o Variable.o Ou.o main
leak:
	valgrind --leak-check=full ./main
