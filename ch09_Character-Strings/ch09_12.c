/* Write a function called strToFloat() that converts a character string into a floating-point value. Have the function
 * accept an optional leading minus sign. So, the call
 * strToFloat ("-867.6921");
 *
 * should return the value −867.6921.
 */

#include <stdio.h>
#include <stdbool.h>

int main (void)
{
    float strToFloat (const char string[]);

    printf ("%.4f\n", strToFloat("-867.6921"));
    printf ("%.2f\n", strToFloat("-100.48") + 25);
    printf ("%.6f\n", strToFloat("13.392875"));

    return 0;
}


float strToFloat (const char string[])
{

    int i, tensToDivide = 1, negative = 1;
    float intValue, result_1 = 0, result_2 = 0;
    bool dot = false;

    for (i = 0; (string[i] >= '0' && string[i] <= '9') || string[i] == '-' || string[i] == '.'; ++i)
    {
        if (string[i] == '-')
        {
            negative = -1;
        }
        else if (string[i] == '.')
        {
            dot = true;
        }
        else if (dot)
        {
            intValue = string[i] - '0';
            tensToDivide *= 10;
            result_2 = result_2 + intValue / tensToDivide;
        }
        else
        {
            intValue = string[i] - '0';
            result_1 = result_1 * 10 + intValue;
        };
    };

    return (float) (result_1 + result_2) * negative;
}