# Makefile Variables
CC		 = gcc
EXEC	 = caseconvert
CFLAGS = -Wall -ansi -pedantic
OBJ 	 = caseconvert.o 
$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

caseconvert.o : caseconvert.c
	$(CC) $(CFLAGS) -c caseconvert.c
clean:
	rm -f $(EXEC) $(OBJ)