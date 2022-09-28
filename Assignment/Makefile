# Makefile Variables
CC		 = gcc
EXEC	 = battleships
CFLAGS = -ansi -pedantic -g -Werror -Wall
OBJ 	 = battleships.o LinkedList.o fileio.o game.o macros.o
$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) -g

# Conditional compilation
ifdef MONO
CFLAGS += -D MONO
MONO : clean $(EXEC)
endif

ifdef DEBUG
CFLAGS += -D DEBUG
DEBUG : clean $(EXEC)
endif


# Object files

battleships.o : battleships.c LinkedList.h fileio.h game.h macros.h
	$(CC) $(CFLAGS) -c battleships.c

LinkedList.o : LinkedList.c LinkedList.h
	$(CC) $(CFLAGS) -c LinkedList.c

fileio.o : fileio.c fileio.h  LinkedList.h  game.h macros.h
	$(CC) $(CFLAGS) -c fileio.c

game.o : game.c LinkedList.h game.h fileio.h macros.h
	$(CC) $(CFLAGS) -c game.c

clean:
	rm -f $(EXEC) $(OBJ)