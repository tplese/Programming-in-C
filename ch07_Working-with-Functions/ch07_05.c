/** The criteria used for termination of the loop in the squareRoot() function of Program 7.8 is not suitable for use when
 * computing the square root of very large or very small numbers.
 * Rather than comparing the difference between the value of x and the value of guess2,
 * the program should compare the ratio of the two values to 1.
 * The closer this ratio gets to 1, the more accurate the approximation of the square root.
 */

#include <stdio.h>

float askUserForNumber ()
{
    float number = 0;

    do
    {
        printf ("Number to squre root (zero for exit): ");
        scanf ("%f", &number);
        while (getchar () != '\n');
    }
    while (number < 0);

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
float  squareRoot (float x)
{
    float guess = 1.0;
    float preventInfiniteLoop = 0;

    while  (absoluteValue (guess * guess / x != 1.0 && preventInfiniteLoop != guess))
    {
        preventInfiniteLoop = guess;
        guess = (x / guess + guess) / 2.0;
        printf ("guess = %f\n", guess);
    }

    return guess;
}


int main (void)
{
    float numberToCalculate;

    do
    {
        numberToCalculate = askUserForNumber ();

        if (numberToCalculate > 0)
        {
            printf ("squareRoot (%f) = %f\n", numberToCalculate, squareRoot (numberToCalculate));
        };

     }
    while (numberToCalculate > 0);

    return 0;
}