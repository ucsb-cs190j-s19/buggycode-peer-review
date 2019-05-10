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

The student, however, is getting this output:
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
h k
s 5
s a

Bob's cards:
d k
c 2
d j
h 8
s 6
d j
h 9
c 3
```

Notice that "d j" is removed from Alice's hand, but not from Bob's. "s a" is removed from Bob's hand, but not from Alice's. "c 3" is removed from Alice's hand, but not from Bob's. "h k" is removed from Bob's hand but not Alice's.
