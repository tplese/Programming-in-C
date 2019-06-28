/** Rewrite the functions developed in the last four exercises to use global variables instead of arguments.
 * For example, the preceding exercise should now sort a globally defined array.
 *
 * c. REWRITE OF ch07_13.c
 */


/** Modify the sort() function from Program 7.12 to take a third argument indicating whether the array is to be sorted in ascending or descending order.
 * Then modify the sort() algorithm to correctly sort the array into the indicated order.
 */

// Program to sort an array of integers into ascending order

#include <stdio.h>

int arraySize = 16;
char orderDirection;
int  array[] = {34, -5, 6, 0, 12, 100, 56, 22,
                       44, -3, -9, 12, 17, 22, 6, 11};

int main (void)
{
    void printoutArray (void);
    char askOrderDirection (void);
    void sort (void);

    printf ("The array before the sort:\n");
    printoutArray ();

    orderDirection = askOrderDirection ();

    sort ();

    printf ("\nThe array after the sort:\n");
    printoutArray ();

    printf ("\n");

    return 0;
}


char askOrderDirection (void)
{
    char userInput = 'z';

    do
    {
        printf ("Do you want the array ordered ascending (a) or descending (d)?  ");

        scanf ("%c", &userInput);
        while (getchar() != '\n');
    }
    while (userInput != 'a' && userInput != 'd');

    return userInput;
}


void printoutArray (void)
{
    for (int i = 0;  i < arraySize;  ++i)
    {
        printf ("%i ", array [i]);
    };

    printf ("\n\n");
}


void  sort (void)
{
    int  i, j, temp;

    for (i = 0;  i < arraySize - 1;  ++i)
    {
        for (j = i + 1;  j < arraySize;  ++j)
        {
            switch (orderDirection)
            {
                case 'a':
                    if (array [i] > array [j])
                    {
                        temp = array [i];
                        array [i] = array [j];
                        array [j] = temp;
                    };
                        break;
                    case 'd':
                        if (array [i] < array [j])
                        {
                            temp = array [i];
                            array [i] = array [j];
                            array [j] = temp;
                        };
                        break;
            };
        };
    };
}