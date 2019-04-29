CXXFLAGS= -Wall -O0 -g


main: main.o
	g++ -o main main.o

main.o: main.cpp
	g++ -o main.o -c ${CXXFLAGS} main.cpp

clean:
	rm main.o main
leak:
	valgrind --leak-check=full ./main
