/* Modify Program 7.14 so that the user can convert any number of integers.
 * Make provision for the program to terminate when a zero is typed in as the value of the number to be converted.
 */

#include <stdio.h>

int main (void)
{
    int chooseScalarNumber (void);
    void scalarMultiply (int nRows, int nCols, int matrix[nRows][nCols], int scalar);
    void displayMatrix (int nRows, int nCols, int  matrix[nRows][nCols]);
    int sampleMatrix[3][5] =
          {
              {  7, 16, 55, 13, 12 },
              { 12, 10, 52,  0,  7 },
              { -2,  1,  2,  4,  9 }
          };

    int scalarNumber = 1;

    printf ("Original matrix:\n");
    displayMatrix (3, 5, sampleMatrix);

    do
    {
        scalarNumber = chooseScalarNumber ();

        if (scalarNumber == 0)
        {
            return 0;
        }
        else
        {
            scalarMultiply (3, 5, sampleMatrix, scalarNumber);
            printf ("\nMultiplied by 2:\n");
            displayMatrix (3, 5, sampleMatrix);
        };
    }
    while (scalarNumber != 0);


    return 0;
}


// Function to get scalar number from user
int chooseScalarNumber (void)
{
    int userNumber = 596;

    do
    {
        printf ("Chose number for multiplying the matrix (-595 to 595): ");
        scanf ("%i", &userNumber);
        while (getchar() != '\n');
    }
    while (userNumber < -595 || userNumber > 595);

    return userNumber;
}



// Function to multiply a matrix by a scalar
void  scalarMultiply (int nRows, int nCols,
                      int  matrix[nRows][nCols], int  scalar)
{
    int  row, column;

    for ( row = 0;  row < nRows;  ++row )
        for ( column = 0;  column < nCols;  ++column )
            matrix[row][column]  *=  scalar;
}


// Function to display matrix
void  displayMatrix (int nRows, int nCols, int  matrix[nRows][nCols])
{
    int   row, column;

    for ( row = 0;  row < nRows;  ++row) {
        for ( column = 0;  column < nCols;  ++column )
            printf ("%10i", matrix[row][column]);

        printf ("\n");
    }
}