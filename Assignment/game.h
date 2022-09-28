#ifndef GAME_H
#define GAME_H

    /* Missile function pointer */
    typedef void(*funcPtr)(char***, int, int, int, int);
                        /* Board, width, height,x,y */

    /* Ship structure */
    typedef struct {

        int x; /* X coordinate where ship head is located */
        int y; /* Y coordinate where ship head is located */
        char direction; /* Direction the ship is facing (from the head -> away in a direction) */
        int length; /* The amount of tiles (including the head) that the ship takes up on the board. */
        char name[256]; /* Name of the ship */
        int dead; /* Integer that keeps track of if a ship is destroyed or not. */
    }Ship;

    /* Missile structure */
    typedef struct {
        char name[10]; /* Name of the missile */
        char detail[50]; /* Missile description */
        funcPtr function; /* Function that modifies the game board in a unique manner */
    }Missile; 

    /* Function forward declarations */
    void playBattleships(int, int, Ship*, LinkedList*, Missile*, LinkedList*); 
    void freeData(void* data);
    void takeTurn( char***, int, int, LinkedList**, LinkedList**, int*, int*);
    void printBoard(char*** board, int width, int height);

    void singleFunc(char*** board, int width, int height, int xPos, int yPos);
    void splashFunc(char*** board, int width, int height, int xPos, int yPos);
    void vlineFunc(char*** board, int width, int height, int xPos, int yPos);
    void hlineFunc(char*** board, int width, int height, int xPos, int yPos);

    void checkShip(char*** Board, int x, int y, int length, char direction, char*, int* , int*);

#endif