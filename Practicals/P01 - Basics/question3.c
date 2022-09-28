#include <stdio.h>
int factorial(int n);

int main(void)

{
    char sign;
    int num;
    int result;

    do
    {
        printf("Please enter a number: \n");
        scanf("%d", &num);
        
        if(num >= 0)
        {
            result = factorial(num);
            printf("The factorial of the given integer is: %d \n", result);
            sign = 'p';
        }
        else
        {
            printf("The number is negative therefore a factorial "
                    "cannot be calculated \n");
            sign = 'n';
        }
    } while(sign != 'n');
    
    return 0;
}

int factorial(int n)
{
    int i;
    int fact;
    fact = 1;
    for(i=1;i<=n;i++)
    {
        fact = fact * i;
        /* printf("%d \n", fact); */
    }
    return fact;
}
