game: main.o cards.o
	g++ main.o cards.o -o game 

main.o: main.cpp cards.h
	g++ main.cpp -c

cards.o: cards.cpp cards.h
	g++ cards.cpp -c -g

testcards: testcards.cpp testcards.h
	g++ testcards.cpp -c



clean:
	rm game testcards main.o cards.o
