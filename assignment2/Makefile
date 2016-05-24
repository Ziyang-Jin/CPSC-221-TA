OBJS = ticket.o ccqueue.o a2simpledriver.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

a2test : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o a2test

ticket.o : ticket.h ticket.cpp
	$(CC) $(CFLAGS) ticket.cpp -o ticket.o

ccqueue.o : ccqueue.h ccqueue.cpp ticket.o linkedlist.h linkedlistprivate.h linkedlist.cpp
	$(CC) $(CFLAGS) ccqueue.cpp -o ccqueue.o

a2simpledriver.o : linkedlist.h linkedlistprivate.h linkedlist.cpp a2simpledriver.cpp
	$(CC) $(CFLAGS) a2simpledriver.cpp -o a2simpledriver.o

clean :
	rm -f *.o *~ a2test
