/** The least common multiple (lcm) of two positive integers u and v is the smallest positive integer
 * that is evenly divisible by both u and v.
 * Thus, the lcm of 15 and 10, written lcm (15, 10), is 30 because 30 is the smallest integer divisible by both 15 and 10.
 * Write a function lcm() that takes two integer arguments and returns their lcm.
 * The lcm() function should calculate the least common multiple by calling the gcd() function from Program 7.6
 * in accordance with the following identity:
 *
 * lcm (u, v) = uv / gcd (u, v)        u, v >= 0
 */

#include <stdio.h>

int main (void)
{
    int askForNumber (char u_v);
    long int lcm (int x, int y);

    int u, v;

    u = askForNumber ('u');
    v = askForNumber ('v');

    printf ("Least common multiple of %i and %i is %li.\n", u, v, lcm (u, v));

    return 0;
}


int askForNumber (char u_v)
{
    int userNumber = -1;

    do
    {
        switch (u_v)
        {
            case 'u':
                printf ("Enter 1st integer (0 to 32767): ");
                break;
            case 'v':
                printf ("Enter 1st integer (0 to 32767): ");
                break;
        };

        scanf ("%i", &userNumber);
        while (getchar() != '\n');
    }
    while (userNumber < 0 || userNumber > 32767);

    return userNumber;
}


// Calculates least common multiple (lcm) of two numbers
long int lcm (int x, int y)
{
    int  gcd (int u, int v);

    return x * y / gcd (x, y);
}


// Calculates greatest common divisor of two numbers
int  gcd (int u, int v)
{
     int  temp;

     while ( v != 0 ) {
         temp = u % v;
         u = v;
         v = temp;
     }

     return u;
}