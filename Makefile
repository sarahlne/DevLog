CXXFLAGS= -Wall -O0 -g


main: main.o Noeud.o Valeur.o
	g++ -o main main.o Noeud.o Valeur.o

main.o: main.cpp
	g++ -o main.o -c ${CXXFLAGS} main.cpp

Noeud.o: Noeud.cpp Noeud.h
	g++ -o Noeud.o -c ${CXXFLAGS} Noeud.cpp

Valeur.o: Valeur.cpp Valeur.h
	g++ -o Valeur.o -c ${CXXFLAGS} Valeur.cpp
clean:
	rm main.o Valeur.o Noeud.o main
leak:
	valgrind --leak-check=full ./main
