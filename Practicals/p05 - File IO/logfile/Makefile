# Makefile Variables
CC		 = gcc
EXEC	 = readlog
CFLAGS = -Wall -ansi -pedantic -Werror
OBJ 	 = readlog.o 
$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

readlog.o : readlog.c 
	$(CC) $(CFLAGS) -c readlog.c
	
clean:
	rm -f $(EXEC) $(OBJ)