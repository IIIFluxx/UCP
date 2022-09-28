#ifndef MACROS_H
#define MACROS_H

    /* Defined macros*/
    #define TRUE 1
    #define FALSE 0
    /* Colours used in displayBoard() */
    #define RED "\033[0;31m"
    #define GREEN "\033[0;32m"
    #define BLUE "\033[1;34m"
    #define RESET "\033[0m"
    #define MAGENTA "\033[1;35m"

    /* Function forward declarations */
    void printError(char* error);
    void spacer();
    void toUpperStr(char *s);
    char toUpper(char ch);
    void printString(void* data);

#endif

