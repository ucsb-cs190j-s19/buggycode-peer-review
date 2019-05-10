game: main.o cards.o
	g++ main.o cards.o -o game
testcards: testcards.o cards.o
	g++ testcards.o -o testcards

main.o: main.cpp
	g++ main.cpp -c
cards.o: cards.h cards.cpp
	g++ cards.cpp -c -g
testcards.o: cards.h testcards.h testcards.cpp
	g++ testcards.cpp -c

clean:
	rm -rf main.o cards.o testcards.o game testcards
