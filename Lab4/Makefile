all: test
	echo "all compiled"

test: lab1testsuite.cpp arrayclass.o
	g++ -Wall lab1testsuite.cpp arrayclass.o -o test

arrayclass.o: arrayclass.h arrayclass.cpp
	g++ -Wall -c arrayclass.h arrayclass.cpp

clean:
	rm -f arrayclass.o
	rm -f test
