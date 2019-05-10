# Contributed by Aesha Parekh
# Build Instructions
### To make and run

`make`

`./game acards.txt bcards.txt`

### Bugs
Student is encountering the following compiler warning and error
```
g++ main.cpp cards.cpp -g -o game
In file included from main.cpp:4:
./cards.h:28:8: warning: unelaborated friend declaration is a C++11 extension;
      specify 'class' to befriend 'CardList' [-Wc++11-extensions]
friend CardList;
       ^
       class
1 warning generated.
In file included from cards.cpp:5:
./cards.h:28:8: warning: unelaborated friend declaration is a C++11 extension;
      specify 'class' to befriend 'CardList' [-Wc++11-extensions]
friend CardList;
       ^
       class
1 warning generated.
dibas-imac:aparekh_pa01_buggy_7 leopard$ vim README.md 
dibas-imac:aparekh_pa01_buggy_7 leopard$ ./game acards.txt bcards.txt 
Alice picked matching card d j
Segmentation fault: 11
```
