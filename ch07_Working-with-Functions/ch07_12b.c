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


int main (void)
{
    int rows, columns;
    int askArraySize (char x);

    rows = askArraySize ('r');
    columns = askArraySize ('c');

    int arrayAB [rows] [columns];
    int arrayBA [columns] [rows];

    void populateArray (int a, int b, int arrayAB [a] [b]);
    void transposeArrays (int a, int b, int arrayAB [a] [b], int arrayBA [b] [a]);

    populateArray (rows, columns, arrayAB);
    transposeArrays (rows, columns, arrayAB, arrayBA);

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


int askArraySize (char x)
{
    int userNumber = -1;

    do
    {
        switch (x)
        {
            case 'r':
                printf ("Set size of rows (1 - 32767):  ");
                break;
            case 'c':
                printf ("Set size of columns (1 - 32767):  ");
        };

        scanf ("%i", &userNumber);
        while (getchar() != '\n');
    }
    while (userNumber <= 0 || userNumber > 32767);

    return userNumber;
}


void populateArray (int a, int b, int arrayAB [a] [b])
{
    srand(time(NULL));

    printf ("Array [%i] [%i]: \n", a, b);

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            arrayAB [i] [j] = rand() % (32766 + 1 - 0) + 0;
            printf ("%5i  ", arrayAB [i] [j]);
        };

        printf ("\n");
    };
}


void transposeArrays (int a, int b, int arrayAB [a] [b], int arrayBA [b] [a])
{
    int index_1 = 0;
    int index_2 = 0;

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (i == 0 && j == 0)
            {
                arrayBA [i] [j] = arrayAB [i] [j];
            }
            else if (index_2 % a == 0)
            {
                index_1++;
            };
            arrayBA [index_1] [index_2 % a] = arrayAB [i] [j];
            index_2++;
        };
    };
}