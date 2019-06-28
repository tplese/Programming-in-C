/** An equation of the form
 * ax2 + bx + c = 0
 *
 * is known as a quadratic equation. The values of a, b, and c in the preceding example represent constant values. So
 * 4x2 - 17x - 15 = 0
 *
 * represents a quadratic equation where a = 4, b = −17, and c = −15.
 * The values of x that satisfy a particular quadratic equation, known as the roots of the equation,
 * can be calculated by substituting the values of a, b, and c into the following two formulas:
 *
 * (Image)
 *
 * If the value of b2−4ac, called the discriminant, is less than zero, the roots of the equation, x1 and x2, are imaginary numbers.
 *
 * Write a program to solve a quadratic equation. The program should allow the user to enter the values for a, b, and c.
 * If the discriminant is less than zero, a message should be displayed that the roots are imaginary;
 * otherwise, the program should then proceed to calculate and display the two roots of the equation.
 * (Note: Be certain to make use of the squareRoot() function that you developed in this chapter.)
 */

#include <stdio.h>

int main (void)
{
    int askForNumber (char a_b_c);
    double calculateEpsilon (int p);
    double squareRoot (int discr, double eps);
    double calculateRoots (int x, int y, double discrSqr, char rootOneTwo);

    int a, b, c, precision, discriminant;
    double epsilon, discriminantSquared;

    do
    {
        a = askForNumber ('a');
        b = askForNumber ('b');
        c = askForNumber ('c');
        precision = askForNumber ('p');

        discriminant = (b * b) - (4 * a * c);
        printf ("Discriminant = %i\n", discriminant);

        if (discriminant > 0)
        {
            epsilon = calculateEpsilon (precision);

            discriminantSquared = squareRoot (discriminant, epsilon);

            printf ("Root 1 = %.16f\n", calculateRoots (a, b, discriminantSquared,'1'));
            printf ("Root 2 = %.16f\n", calculateRoots (a, b, discriminantSquared, '2'));
        }
        else
        {
            printf ("Roots are imaginary (discriminant is less than zero).\n");
        };
    }
    while (discriminant > 0);


    return 0;
}


int askForNumber (char a_b_c)
{
    int userNumber = -32768;

    do
    {
        switch (a_b_c)
        {
            case 'a':
                printf ("Enter integer a: ");
                break;
            case 'b':
                printf ("Enter integer b: ");
                break;
            case 'c':
                printf ("Enter integer c: ");
                break;
            case 'p':
                printf ("Enter precision of epsilon (1-16): ");
                break;
        };

        scanf ("%i", &userNumber);
        while (getchar() != '\n');
    }
    while (userNumber < -32766 || userNumber > 32767);

    return userNumber;
}


double calculateEpsilon (int p)
{
    double eps = 1.0;

    for (int i = 0; i < p; i++)
    {
        eps /= 10;
    };

    printf ("Epsilon = %.16f\n", eps);

    return eps;
}


// Function to compute the square root of a number
double  squareRoot (int discr, double eps)
{
    float absoluteValue (float x);

    double guess = 1.0;
    double preventInfiniteLoop = 0;

    while  (absoluteValue (guess * guess - discr) >= eps && preventInfiniteLoop != guess)
    {
        preventInfiniteLoop = guess;
        guess = (discr / guess + guess) / 2.0;
        //printf ("guess = %.16f\n", guess);
    };

    return guess;
}


float absoluteValue (float x)
{
    if ( x < 0 )
    {
        x = -x;
    };

    return (x);
}


double calculateRoots (int x, int y, double discrSqr, char rootOneTwo)
{
    double rootResult;

    switch (rootOneTwo)
    {
        case '1':
            rootResult = (-y + discrSqr) / (2 * x);
            break;
        case '2':
            rootResult = (-y - discrSqr) / (2 * x);
            break;
    };

    return rootResult;
}