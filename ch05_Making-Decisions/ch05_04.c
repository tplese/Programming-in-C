#include <stdio.h>

int main (void)
{
    float number = 0;
    float sum = 0;
    char operation = 'c';
    
    printf ("Welcome to this simple calculator.\n");
    printf ("Please give me a number and an operator.\n");
    printf ("Valid operators: +, -, *, /, S (sum) and E (exit).\n");

    while (operation != 'E')
    {
        scanf ("%f %c", &number, &operation);
        
        switch (operation)
        {
            case '+':
                sum = sum + number;
                printf ("= %g (Current SUM)\n", sum);
                break;
            case '-':
                sum = sum - number;
                printf ("= %g (Current SUM)\n", sum);
                break;
            case '*':
                sum = sum * number;
                printf ("= %g (Current SUM)\n", sum);
                break;
            case '/':
                sum = sum / number;
                printf ("= %g (Current SUM)\n", sum);
                break;
            case 'S':
                sum = number;
                printf ("= %g  (Current SUM)\n", sum);
                break;
            case 'E':
                break;
            default:
                printf ("Quit messing around and give me valid number and valid operator.\n");    
        };
    };
    
    return 0;
}