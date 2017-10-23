
all: main

main: main.o ItemType.o DoublyLinkedList.o
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -o main main.o ItemType.o DoublyLinkedList.o

main.o: main.cpp ItemType.h DoublyLinkedList.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c main.cpp

ItemType.o: ItemType.cpp ItemType.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c ItemType.cpp
 
DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h ItemType.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c DoublyLinkedList.cpp

clean:
	rm -rf main
	rm -rf *.o