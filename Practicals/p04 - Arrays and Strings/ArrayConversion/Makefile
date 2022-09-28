# Makefile Variables
CC		 = gcc
EXEC	 = ArrayConversion
CFLAGS = -Wall -ansi -pedantic
OBJ 	 = ArrayConversion.o
$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

ArrayConversion.o : ArrayConversion.c
	$(CC) $(CFLAGS) -c ArrayConversion.c
clean:
	rm -f $(EXEC) $(OBJ)