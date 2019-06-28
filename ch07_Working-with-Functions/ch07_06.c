/** Modify Program 7.8 so that the squareRoot() function accepts a double precision argument and returns the result as a double precision value.
 * Be certain to change the value of the variable epsilon to reflect the fact that double precision variables are now being used.
 */

// Function to calculate the absolute value of a number
#include <stdio.h>

float askForPrecision ()
{
    int precision = -1;
    double epsilon = 1.0;

    do
    {
        printf ("Set precision from 1 - 16 (highest), 0 to exit: ");
        scanf ("%i", &precision);
        while (getchar () != '\n');
    }
    while (!(precision >= 0 && precision <= 16));

    for (int i = 0; i < precision; i++)
    {
        epsilon /= 10;
    };

    printf ("Epsilon = %.16f\n", epsilon);

    return epsilon;
}

float askUserForNumber ()
{
    float number = -1.0;

    do
    {
        printf ("Number to squre root: ");
        scanf ("%f", &number);
        while (getchar () != '\n');
    }
    while (number <= 0);

    return number;
}

float absoluteValue (float x)
{
    if ( x < 0 )
    {
        x = -x;
    }

    return (x);
}


// Function to compute the square root of a number
double  squareRoot (float x, double eps)
{
    double guess = 1.0;
    double preventInfiniteLoop = 0;

    while  (absoluteValue (guess * guess - x) >= eps && preventInfiniteLoop != guess)
    {
        preventInfiniteLoop = guess;
        guess = (x / guess + guess) / 2.0;
        printf ("guess = %.16f\n", guess);
    }

    return guess;
}


int main (void)
{
    double epsilon;
    float numberToCalculate;

    do
    {
        epsilon = askForPrecision ();

        if (epsilon > 0 && epsilon < 1.0)
        {
            numberToCalculate = askUserForNumber ();
            printf ("squareRoot (%.7f) = %.16f\n", numberToCalculate, squareRoot (numberToCalculate, epsilon));
        };

    }
    while (epsilon != 1.0);

    return 0;
}