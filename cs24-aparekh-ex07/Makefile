# game: main.o cards.o
# 	g++ -g main.o cards.o -o game
# 	./game acards.txt bcards.txt

# main.o: main.cpp
# 	g++ -g main.cpp -c

# testcards: testcards.o cards.o
# 	g++  testcards.o cards.o -o testcards

# testcards.o: testcards.cpp testcards.h cards.h
# 	g++ -g testcards.cpp -c
game: main.cpp cards.cpp
	g++ main.cpp cards.cpp -g -o game
testcards: testcards.cpp cards.cpp
	g++ testcards.cpp cards.cpp -g -o testcards
clean:
	rm game testcards *.o
