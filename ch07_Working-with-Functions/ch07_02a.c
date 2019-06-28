/** 2. a) Modify Program 7.4 so the value of triangularNumber is returned by the function.
  * b) Then go back to Program 4.5 and change that program so that it calls the new version
  * of the calculateTriangularNumber() function.
 */

// 7.4. Function to calculate the nth triangular number

#include <stdio.h>

int calculateTriangularNumber (int n)
{
    int i;
    int triangularNumber = 0;

    for (i = 1; i <= n; ++i )
        triangularNumber += i;

    return triangularNumber;

}

void displayTriangularNumber (int n, int triangularNumber)
{
    printf ("Triangular number %i is %i\n", n, triangularNumber);
}

int main (void)
{
    int n;

    n = 10;
    displayTriangularNumber (n, calculateTriangularNumber (n));

    n = 20;
    displayTriangularNumber (n, calculateTriangularNumber (n));

    n = 50;
    displayTriangularNumber (n, calculateTriangularNumber (n));

    return 0;
}