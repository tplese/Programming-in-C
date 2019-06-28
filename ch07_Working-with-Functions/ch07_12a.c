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
    void populateArray (int array4x5 [4] [5]);
    void transposeArrays (int array4x5 [4] [5], int array5x4 [5] [4]);

    int array4x5 [4] [5];
    int array5x4 [5] [4];

    populateArray (array4x5);
    transposeArrays (array4x5, array5x4);

    printf ("Array 5 x 4: \n");

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf ("%5i  ", array5x4 [i] [j]);
        };

        printf ("\n");
    };

    return 0;
}


void populateArray (int array4x5 [4] [5])
{
    srand(time(NULL));

    printf ("Array 4 x 5: \n");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            array4x5 [i] [j] = rand() % (32766 + 1 - 0) + 0;
            printf ("%5i  ", array4x5 [i] [j]);
        };

        printf ("\n");
    };
}


void transposeArrays (int array4x5 [4] [5], int array5x4 [5] [4])
{
    int index_1 = 0;
    int index_2 = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 0 && j == 0)
            {
                array5x4 [i] [j] = array4x5 [i] [j];
            }
            else if (index_2 % 4 == 0)
            {
                index_1++;
            };
            array5x4 [index_1] [index_2 % 4] = array4x5 [i] [j];
            index_2++;
        };
    };
}