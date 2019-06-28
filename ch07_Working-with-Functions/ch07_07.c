/** Write a function that raises an integer to a positive integer power. Call the function x_to_the_n()
 * taking two integer arguments x and n. Have the function return a long int, which represents the results of calculating xn.
 */

#include <stdio.h>

int main (void)
{
    int theInteger, thePower;

    int askForNumber(char intOrPwr);
    long int x_to_the_n(int x, int n);

    do
    {
        theInteger = askForNumber ('i');

        if (theInteger != 0)
        {
            thePower = askForNumber ('p');
        };

        if (theInteger != 0 && thePower != 0)
        {
            printf ("OUTPUT: %i^%i = %10ld\n", theInteger, thePower, x_to_the_n (theInteger, thePower));
        };

    }
    while (theInteger != 0 && thePower != 0);

    return 0;
}

int askForNumber (char intOrPwr)
{
    int userNumber = -1;

    do
    {
        if (intOrPwr == 'i')
        {
            printf ("Integer to raise (0 to exit): ");
        }
        else if (intOrPwr == 'p')
        {
            printf ("Raise to power of (0 to exit): ");
        };

        scanf ("%i", &userNumber);
        while (getchar () != '\n');

    }
    while (userNumber < 0 || userNumber > 32767);

    return userNumber;
}


long int x_to_the_n(int x, int n)
{
    long int result = 1;

    for (int i = 0; i < n; i++)
    {
        result *= x;
        printf ("result = %li\n", result);
    };

    return result;
}