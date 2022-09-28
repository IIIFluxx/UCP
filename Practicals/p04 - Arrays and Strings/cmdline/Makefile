# Makefile Variables
CC		 = gcc
EXEC	 = cmdline
CFLAGS = -Wall -ansi -pedantic
OBJ 	 = cmdline.o ArrayConversion.o math.o ArrayOutput.o caseconvert.o
$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

cmdline.o : cmdline.c ArrayConversion.h math.h ArrayOutput.h caseconvert.h
	$(CC) $(CFLAGS) -c cmdline.c

ArrayConversion.o : ArrayConversion.c ArrayConversion.h
	$(CC) $(CFLAGS) -c ArrayConversion.c
	
math.o : math.c math.h
	$(CC) $(CFLAGS) -c math.c

ArrayOutput.o : ArrayOutput.c ArrayOutput.h
	$(CC) $(CFLAGS) -c ArrayOutput.c

caseconvert.o : caseconvert.c caseconvert.h
	$(CC) $(CFLAGS) -c caseconvert.c
clean:
	rm -f $(EXEC) $(OBJ)


	