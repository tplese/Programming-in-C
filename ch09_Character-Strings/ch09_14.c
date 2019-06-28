/* Write a function called intToStr() that converts an integer value into a character string.
 * Be certain the function handles negative integers properly.
 */

#include <stdio.h>
#include <stdbool.h>

int main (void)
{
    int askForInt (void);
    void intToStr (const char zeroToNine [], char numbersText [], int userNumber);
    void printOutString (char bufferString []);

    const char allNumbers [] = "0123456789";
    char stringOfNumbers [6];

    printf ("Type in an positive or negative integer: ");
    int number = askForInt ();

    printf ("Your number as a string: ");
    intToStr (allNumbers, stringOfNumbers, number);
    printOutString (stringOfNumbers);

    return 0;
}


int askForInt (void)
{
    int number;

    do
    {
        scanf ("%i", &number);
    }
    while (number <= -32768 || number >= 32767);

    return number;
}


void intToStr (const char zeroToNine [], char numbersText [], int userNumber)
{
    int numberOfDigits (int num);

    int digits = numberOfDigits (userNumber);

    int ending;
    bool minus;

    if (userNumber < 0)
    {
        minus = true;
        ending = 1;
        userNumber *= -1;
    }
    else
    {
        ending = 0;
        digits--;
        minus = false;
    }

    int bufferInt;
    for (; digits >= ending; digits--)
    {
        bufferInt = userNumber % 10;
        numbersText [digits] = zeroToNine [bufferInt];
        userNumber = userNumber / 10;
    };

    if (minus)
    {
        numbersText [0] = '-';
    };
}


int numberOfDigits (int num)
{
    int count = 0;

    if (num != 0)
    {
        while (num != 0)
        {
            num = num / 10;
            count++;
        };
    }
    else
    {
        count = 1;
    };

    return count;
}


void printOutString (char bufferString [])
{
    int i = 0;

    while (bufferString [i] != '\0')
    {
        printf ("%c", bufferString [i]);
        i++;
    };

    printf ("\n");
}