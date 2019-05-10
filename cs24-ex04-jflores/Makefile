game: cards.o main.o
	g++ cards.o main.o -o game

testcards: cards.o testcards.o
	g++ cards.o testcards.o -o testcards
main.o:
	g++ main.cpp -c
cards.o:
	g++ cards.cpp -c -g
testcards.o:
	g++ testcards.cpp -c
clean:
	rm -rf game testcards *.o
