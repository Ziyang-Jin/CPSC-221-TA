all : dates lists 
	echo "all compiled"

dates : dates.cpp CDate.o Unit.o 
	g++ -Wall dates.cpp CDate.o Unit.o  -o dates

CDate.o : CDate.cpp CDate.h 
	g++ -Wall -c CDate.cpp -o CDate.o 

lists : lists.cpp linked_list.cpp Unit.o
	g++ -Wall lists.cpp Unit.o -o lists 

Unit.o : Unit.cpp Unit.h  
	g++ -Wall -c Unit.cpp -o Unit.o 

clean :
	rm -f CDate.o 
	rm -f dates 
	rm -f Unit.o 
	rm -f lists
 
