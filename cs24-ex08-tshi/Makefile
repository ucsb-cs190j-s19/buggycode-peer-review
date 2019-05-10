test: testcards.o cards.o
	g++ testcards.o cards.o -o test
play: main.o cards.o
	g++ main.o cards.o -o play
main.o: main.cpp cards.h
	g++ main.cpp -c
testcards.o: testcards.h testcards.cpp
	g++ testcards.cpp -c
cards.o: cards.h cards.cpp
	g++ cards.cpp -c
clean:
	rm test play main.o testcards.o cards.o
