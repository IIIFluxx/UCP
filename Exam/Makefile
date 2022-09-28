# Makefile Variables
CC		 = gcc
EXEC	 = main
CFLAGS = -ansi -pedantic -g -Werror -Wall
OBJ 	 = main.o functions.o linkedlist.o 
$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) -g

# Object files

main.o : main.c linkedlist.h functions.h
	$(CC) $(CFLAGS) -c main.c

functions.o : functions.c linkedlist.h functions.h
	$(CC) $(CFLAGS) -c functions.c

linkedlist.o : linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.c

clean:
	rm -f $(EXEC) $(OBJ)