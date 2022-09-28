# Makefile Variables
CC		 = gcc
EXEC	 = math
CFLAGS = -Wall -ansi -pedantic
OBJ 	 = math.o
$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

math.o : math.c
	$(CC) $(CFLAGS) -c math.c
clean:
	rm -f $(EXEC) $(OBJ)