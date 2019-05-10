# Contributed by Jared Flores
# Build Instructions
### To make and run

`make`

`./game acards.txt bcards.txt`

### Bugs
The expected output can be found in `ab_output.txt`. It should read as follows:
```
Alice picked matching card d j
Bob picked matching card s a
Alice picked matching card c 3
Bob picked matching card h k

Alice's cards:
h 3
s 2
c a
c q
d 9
s 5

Bob's cards:
d k
c 2
h 8
s 6
d j
h 9
```

After printing the matching cards, the student's implementation will start printing the player's hand. However, after printing "s 5" (the last card in Alice's hand after all the matching cards are removed), several junk values are printed until the program exits with a segmentation fault.
