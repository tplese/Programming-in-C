/** Modify the sort() function from Program 7.12 to take a third argument indicating whether the array is to be sorted in ascending or descending order.
 * Then modify the sort() algorithm to correctly sort the array into the indicated order.
 */

// Program to sort an array of integers into ascending order

#include <stdio.h>

int main (void)
{
    int  i;
    char orderDirection;
    int  array[16] = {34, -5, 6, 0, 12, 100, 56, 22,
                       44, -3, -9, 12, 17, 22, 6, 11};

    char askOrderDirection (void);
    void printoutArray (int a [16]);
    void sort (int  a[], int  n, char direction);

    orderDirection = askOrderDirection ();

    printf ("The array before the sort:\n");
    printoutArray (array);


    sort (array, 16, orderDirection);

    printf ("\n\nThe array after the sort:\n");
    printoutArray (array);

    printf ("\n");

    return 0;
}


char askOrderDirection (void)
{
    char userInput = 'z';

    do
    {
        printf ("Do you want the array ordered ascending (a) or descending (d)?");

        scanf ("%c", &userInput);
        while (getchar() != '\n');
    }
    while (userInput != 'a' && userInput != 'd');

    return userInput;
}


void printoutArray (int a [16])
{
    for (int i = 0;  i < 16;  ++i)
    {
        printf ("%i ", a [i]);
    };
}


void  sort (int  a[], int  n, char direction)
{
    int  i, j, temp;

    for (i = 0;  i < n - 1;  ++i)
    {
        for (j = i + 1;  j < n;  ++j)
        {
            switch (direction)
            {
                case 'a':
                    if (a[i] > a[j])
                    {
                        temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                    };
                        break;
                    case 'd':
                        if (a[i] < a[j])
                        {
                            temp = a[i];
                            a[i] = a[j];
                            a[j] = temp;
                        };
                        break;
            };
        };
    };
}