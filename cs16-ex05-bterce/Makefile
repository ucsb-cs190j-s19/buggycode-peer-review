CXX = g++
# CXX = clang++

CXXFLAGS = -Wall -Wno-uninitialized

BINARIES=utilityTest

all: ${BINARIES}

tests: ${BINARIES}
	./utilityTest

utilityTest: utilityTest.o tddFuncs.o utility.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o
