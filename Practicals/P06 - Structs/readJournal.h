#ifndef READJOURNAL_H
#define READJOURNAL_H

/* Format:
    1. The first line of each entry contains the date (in “day/month/year” format) 
    2. and the second contains the text. The text can be up to 100 characters long, not including the new-line character (101)
    

    e.g. from lecture
    
    typedef struct {
        int mark;
        char grade;
        } Result;
*/
typedef struct 
{
    int day;
    int month;
    int year;
    char* text;
} Entry;


#endif
