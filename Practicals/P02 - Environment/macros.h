/*

(a)Set up header guards
(b)Create macros for TRUE and FALSE 

*/

#ifndef MACROS_H

#define MACROS_H

#define FALSE 0 
#define TRUE !FALSE

#define BETWEEN(x,y,z) (((x) <= (z)) && ((z) <= (y)))
/* x = lower bound, y = upper bound, z = num inputted */


#endif
