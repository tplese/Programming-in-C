/** Rewrite the functions developed in the last four exercises to use global variables instead of arguments.
 * For example, the preceding exercise should now sort a globally defined array.
 *
 * c. REWRITE OF ch07_12b.c
 */




/** A matrix M with i rows, j columns can be transposed into a matrix N having j rows and i columns
 * by simply setting the value of N(a,b) equal to the value of M(b,a) for all relevant values of a and b.
 *
 * a. Write a function transposeMatrix() that takes as an argument a 4 × 5 matrix and a 5 × 4 matrix.
 * Have the function transpose the 4 × 5 matrix and store the results in the 5 × 4 matrix.
 * Also write a main() routine to test the function.
 *
 * b. Using variable-length arrays, rewrite the transposeMatrix() function developed in exercise 12a
 * to take the number of rows and columns as arguments, and to transpose the matrix of the specified dimensions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char x = 'r';
int rows, columns;

int arrayAB [15000] [15000];
int arrayBA [15000] [15000];


int main (void)
{
    int askArraySize (void);

    rows = askArraySize ();
    columns = askArraySize ();

    void populateArray (void);
    void transposeArrays (void);

    populateArray ();
    transposeArrays ();

    printf ("Array [%i] [%i]: \n", columns, rows);

    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf ("%5i  ", arrayBA [i] [j]);
        };

        printf ("\n");
    };

    return 0;
}


int askArraySize (void)
{
    int userNumber = -1;

    do
    {
        switch (x)
        {
            case 'r':
                printf ("Set size of rows (1 - 15000):  ");
                x = 'r' - 15;
                break;
            case 'c':
                printf ("Set size of columns (1 - 15000):  ");
        };

        scanf ("%i", &userNumber);
        while (getchar() != '\n');
    }
    while (userNumber <= 0 || userNumber > 15000);

    return userNumber;
}


void populateArray (void)
{
    srand(time(NULL));

    printf ("Array [%i] [%i]: \n", rows, columns);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            arrayAB [i] [j] = rand() % (32767 + 1 - 0) + 0;
            printf ("%5i  ", arrayAB [i] [j]);
        };

        printf ("\n");
    };
}


void transposeArrays (void)
{
    int index_1 = 0;
    int index_2 = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i == 0 && j == 0)
            {
                arrayBA [i] [j] = arrayAB [i] [j];
            }
            else if (index_2 % rows == 0)
            {
                index_1++;
            };
            arrayBA [index_1] [index_2 % rows] = arrayAB [i] [j];
            index_2++;
        };
    };
}