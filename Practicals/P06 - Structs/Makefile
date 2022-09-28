# Makefile Variables
CC		 = gcc
EXEC	 = LinkedListTest
CFLAGS = -Wall -ansi -pedantic -Werror -g
OBJ 	 = LinkedListTest.o LinkedList.o
$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

LinkedListTest.o : LinkedListTest.c LinkedList.h 
	$(CC) $(CFLAGS) -c LinkedListTest.c
LinkedList.o : LinkedList.c LinkedList.h
	$(CC) $(CFLAGS) -c LinkedList.c
clean:
	rm -f $(EXEC) $(OBJ)