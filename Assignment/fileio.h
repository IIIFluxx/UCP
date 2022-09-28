#ifndef FILEIO_H
#define FILEIO_H

    /* Function forward declarations */
    int readSettings(char** argv, int* width, int* height, Ship* ship, LinkedList* shipList);
    int convertLocation(char* tempLocation, int* tempX, int* tempY);
    int readMissile(char** argv, Missile* missile, LinkedList* missileList);
    int validateBoard(int inWidth, int inHeight);
    int validateShip(int *width, int *height, int, int, char tempDirection, int tempLength, char* tempName);
    funcPtr assignFunc(char* missile, int* error);
    
    void missileDescription(char* name, char* description);
    
    void createBoard();
    void createMissile();
    
#endif