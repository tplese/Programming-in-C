/** Modify Program 7.8 so that the value of epsilon is passed as an argument to the function.
 * Try experimenting with different values of epsilon to see the effect that it has on the value of the square root.
 */

// Function to calculate the absolute value of a number

#include <stdio.h>

float askForPrecision ()
{
    int precision = -1;
    float epsilon = 1.0;

    do
    {
        printf ("Set precision from 1 - 6 (highest), 0 to exit: ");
        scanf ("%i", &precision);
        while (getchar () != '\n');
    }
    while (!(precision >= 0 && precision <= 6));

    for (int i = 0; i < precision; i++)
    {
        epsilon /= 10;
    };

    printf ("Epsilon = %f\n", epsilon);

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
float  squareRoot (float x, float eps)
{
    float guess = 1.0;
    float preventInfiniteLoop = 0;

    while  (absoluteValue (guess * guess - x) >= eps && preventInfiniteLoop != guess)
    {
        preventInfiniteLoop = guess;
        guess = (x / guess + guess) / 2.0;
        printf ("guess = %f\n", guess);
    }

    return guess;
}


int main (void)
{
    float epsilon;
    float numberToCalculate;

    do
    {
        epsilon = askForPrecision ();

        if (epsilon > 0 && epsilon < 1.0)
        {
            numberToCalculate = askUserForNumber ();
            printf ("squareRoot (%.2f) = %f\n", numberToCalculate, squareRoot (numberToCalculate, epsilon));
        };

    }
    while (epsilon != 1.0);

    return 0;
}