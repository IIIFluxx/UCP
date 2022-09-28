/*

Header guard for all functions within orders.c -- ascending2(), ascending3() & descending3().

*/
typedef void(*funcpoint)(int*,int*,int*);

void ascending2(int* x, int* y);
void ascending3(int* x, int* y, int* z);
void descending3(int* x, int* y, int* z);

funcpoint order(char c);


/* type def ---   void(*order(char c))(int*,..)     
so order(char c) is like the name of the function, beign assigned to the funcpoint's properties*/

/* in numbers.c 
fp = order(option);

	(*fp)(ptrX, ptrY, ptrZ);*/