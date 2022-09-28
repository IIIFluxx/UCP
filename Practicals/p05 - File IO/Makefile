# Makefile Variables
CC		 = gcc
EXEC1	 = display
EXEC2	 = generate
OBJ1 	 = display.o plot.o 
OBJ2 	 = generate.o randomarray.o
CFLAGS = -Wall -ansi -pedantic -Werror 
all : $(EXEC1) $(EXEC2)

$(EXEC1) : $(OBJ1)
	$(CC) $(OBJ1) -o $(EXEC1) -g

$(EXEC2) : $(OBJ2)
	$(CC) $(OBJ2) -o $(EXEC2) -g

display.o : display.c  display.h plot.h
	$(CC) $(CFLAGS) -c display.c

plot.o : plot.c plot.h
	$(CC) $(CFLAGS) -c plot.c

generate.o : generate.c randomarray.h
	$(CC) $(CFLAGS) -c generate.c

randomarray.o : randomarray.c randomarray.h
	$(CC) $(CFLAGS) -c randomarray.c
	
clean:
	rm -f $(EXEC1) $(OBJ1) $(EXEC2) $(OBJ2) 

