/* Extend the strToInt() function from Program 9.11 so that if the first character of the string is a minus sign, the
 * value that follows is taken as a negative number.
 */

// Function to convert a string to an integer
#include <stdio.h>


int main (void)
{
    int strToInt (const char string[]);

    printf ("%i\n", strToInt("-245"));
    printf ("%i\n", strToInt("-100") + 25);
    printf ("%i\n", strToInt("-13x5"));

    return 0;
}


int strToInt (const char string[])
{

    int i, intValue, negative = 1, result = 0;

    for (i = 0; (string[i] >= '0' && string[i] <= '9') || string[i] == '-'; ++i)
    {
        if (string[i] == '-')
        {
            negative = -1;
        }
        else
        {
            intValue = string[i] - '0';
            result = result * 10 + intValue;
        };
    };

    return result * negative;
}