
all: main

main: main.o ItemType.o LinkedList.o
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -o main main.o ItemType.o LinkedList.o

main.o: main.cpp ItemType.h LinkedList.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c main.cpp

ItemType.o: ItemType.cpp ItemType.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c ItemType.cpp
 
LinkedList.o: LinkedList.cpp LinkedList.h ItemType.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c LinkedList.cpp

clean:
	rm -rf main
	rm -rf *.o