/* Write a pointer version of the sort() function from Chapter 7, “Working with Functions.”
 * Be certain that pointers are exclusively used by the function, including index variables in the loops.
 *
 *
// Program to sort an array of integers into ascending order
#include <stdio.h>

void sort (int a[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            };
        };
    };
}

int main (void)
{
    int i;
    int array[16] = {34, -5, 6, 0, 12, 100, 56, 22,
                       44, -3, -9, 12, 17, 22, 6, 11};
    void sort (int a[], int n);

    printf ("The array before the sort:\n");

    for (i = 0; i < 16; ++i)
        printf ("%i ", array[i]);

    sort (array, 16);

    printf ("\n\nThe array after the sort:\n");

    for (i = 0; i < 16; ++i )
        printf ("%i ", array[i]);

    printf ("\n");

    return 0;
}
 */


#include <stdio.h>

int main (void)
{
    void printout (int a[], int n);
    void sort (int *a, int n);

    int i;
    int array[16] = {34, -5, 6, 0, 12, 100, 56, 22,
                       44, -3, -9, 12, 17, 22, 6, 11};

    printf ("The array before the sort:\n");
    printout (array, 16);

    sort (array, 16);

    printf ("\n\nThe array after the sort:\n");
    printout (array, 16);

    printf ("\n");

    return 0;
}

void printout (int a[], int n)
{
    int *ptr_i;
    int * const arrayEnd = a +n;

    for (ptr_i = a; ptr_i < arrayEnd; ++ptr_i)
    {
        printf ("%i ", *ptr_i);
    };
}


void sort (int *a, int n)
{
    int temp;
    int *ptr_j;
    int * const arrayEnd = a + n;

    for (; a < arrayEnd - 1; ++a)
    {
        for (ptr_j = a + 1; ptr_j < arrayEnd; ++ptr_j)
        {
            if (*a > *ptr_j)
            {
                temp = *a;
                *a = *ptr_j;
                *ptr_j = temp;
            };
        };
    };
}