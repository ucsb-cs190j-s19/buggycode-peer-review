# Contributed by Jared Flores
# Build Instructions
### To make and run

`make`

`./game acards.txt bcards.txt`

### Bugs
The programming assignment isn't compiling correctly. If the student uses `#include cards.cpp` in his `main.cpp` file, it seems to compile properly. However, when using the conventionally correct `#include cards.h`, the compiler does not seem to recognize the overloaded ostream << operator.
