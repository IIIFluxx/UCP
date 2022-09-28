# Makefile Variables
CC		 = gcc
EXEC	 = bounds
CFLAGS = -Wall -ansi -pedantic
OBJ 	 = bounds.o powers.o
$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

bounds.o : bounds.c powers.h macros.h
	$(CC) $(CFLAGS) -c bounds.c
powers.o : powers.c
	$(CC) $(CFLAGS) -c powers.c 
clean:
	rm -f $(EXEC) $(OBJ)