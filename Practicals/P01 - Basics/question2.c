/* 1. Prompt q
   2. Read in both numbers (integers)
   3. Division operation
   4. if *divisible* -- output
      if *not divisible* -- output */

#include <stdio.h>

int main(void)
{
    int num1, num2;
    num1 = 0;
    num2 = 0;
    printf("Please enter the first integer: ");
    scanf("%d", &num1);

    printf("Please enter the second integer: ");
    scanf("%d", &num2);
    
    if(num1 % num2 == 0)
    {
        printf("The two chosen integers are divisible. ");
    }
    else
    {
        printf("The two chosen integers are not divisible. ");
    }
    return 0;
}
