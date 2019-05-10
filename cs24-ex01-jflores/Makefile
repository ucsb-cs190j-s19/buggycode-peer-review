#MAKEFILE
CXX_FLAG = --std=c++11 -g

game: main.o cards.o
	g++ $(CXX_FLAG) -o game $^

main.o: main.cpp
	g++ -c $^

cards.o: cards.cpp cards.h
	g++ -c -g $^

testcards: testcards.cpp testcards.h 
	g++ $(CXX_FLAG) -o testcards testcards.cpp 

clean:
	rm -rf *.o game testcards
