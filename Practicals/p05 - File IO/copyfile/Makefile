# Makefile Variables
CC		 = gcc
EXEC	 = copyfile
CFLAGS = -Wall -ansi -pedantic -Werror
OBJ 	 = copyfile.o 
$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

copyfile.o : copyfile.c 
	$(CC) $(CFLAGS) -c copyfile.c
clean:
	rm -f $(EXEC) $(OBJ)