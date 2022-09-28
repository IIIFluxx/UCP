# Makefile Variables
CC		 = gcc
EXEC	 = numbers
CFLAGS = -Wall -ansi -pedantic
OBJ 	 = numbers.o orders.o user_input.o
$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

numbers.o : numbers.c orders.h user_input.h
	$(CC) $(CFLAGS) -c numbers.c
orders.o : orders.c
	$(CC) $(CFLAGS) -c orders.c 
user_input.o : user_input.c
	$(CC) $(CFLAGS) -c user_input.c
clean:
	rm -f $(EXEC) $(OBJ)