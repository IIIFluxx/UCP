# Makefile Variables
CC		 = gcc
EXEC	 = ArrayOutput
CFLAGS = -Wall -ansi -pedantic
OBJ 	 = ArrayOutput.o
$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

ArrayOutput.o : ArrayOutput.c
	$(CC) $(CFLAGS) -c ArrayOutput.c
clean:
	rm -f $(EXEC) $(OBJ)