/** Modify Program 7.14 so that the user is asked again to type in the value of the base if an invalid base is entered.
 * The modified program should continue to ask for the value of the base until a valid response is given.
 */

#include <stdio.h>

int main (void)
{

    int chooseBase (void);
    void scalarMultiply (int nRows, int nCols, int  matrix[nRows][nCols], int scalar);
    void displayMatrix (int nRows, int nCols, int  matrix[nRows][nCols], int base);
    int   sampleMatrix[3][5] =
          {
              {  7, 16, 55, 13, 12 },
              { 12, 10, 52,  0,  7 },
              { -2,  1,  2,  4,  9 }
          };
    int matrixBase;
    int convertedMatrix[3][5];

    matrixBase = chooseBase ();

    // ORIGINAL MATRIX
    printf ("Original matrix:\n");
    displayMatrix (3, 5, sampleMatrix, 10);

    printf ("Original matrix - Converted:\n");
    displayMatrix (3, 5, sampleMatrix, matrixBase);


    // MULTIPLIED BY 2
    scalarMultiply (3, 5, sampleMatrix, 2);
    printf ("\n\nMultiplied by 2:\n");
    displayMatrix (3, 5, sampleMatrix, 10);

    printf ("Multiplied by 2 - Converted:\n");
    displayMatrix (3, 5, sampleMatrix, matrixBase);


    // MULTIPLIED BY -1
    scalarMultiply (3, 5, sampleMatrix, -1);
    printf ("\n\nThen multiplied by -1:\n");
    displayMatrix (3, 5, sampleMatrix, 10);

    printf ("Multiplied by -1 - Converted:\n");
    displayMatrix (3, 5, sampleMatrix, matrixBase);

    return 0;
}

// Function where user chooses base
int chooseBase (void)
{
     int base = -1;

     do
     {
         printf ("Choose base (2 to 16) for the matrix: ");
         scanf ("%i", &base);
         while (getchar() != '\n');
     }
     while (base < 2 || base > 16);

     return base;
}


// Function that displays matrix
void displayMatrix (int nRows, int nCols, int matrix[nRows][nCols], int base)
{
    void convertNumber (int x, int minus, int base);
    int row, column, numberToConvert;
    int minusToggle;

    for ( row = 0;  row < nRows;  ++row) {
        for (column = 0;  column < nCols;  ++column)
        {
            if (base == 10)
            {
                printf ("%5i", matrix[row][column]);
            }
            else
            {
                numberToConvert = matrix[row][column];

                if (numberToConvert < 0)
                {
                    minusToggle = 1;
                    numberToConvert *= -1;
                }
                else
                {
                    minusToggle = 0;
                };

                convertNumber (numberToConvert, minusToggle, base);
            };
        };

        printf ("\n");
    }
}


// Function converts number from base 10 to user-chosen base
void convertNumber (int x, int minus, int base)
{
    void displayConvertedNumber (int convertedArray[16], int numOfDigits, int minus);
    int convertedNumber[16];
    int numOfDigits = 0;

    do
    {
         convertedNumber[numOfDigits] = x % base;
         ++numOfDigits;
         x /= base;
    }
    while  (x != 0);

    displayConvertedNumber (convertedNumber, numOfDigits, minus);
}


// Function that displays proper base symbols
void displayConvertedNumber (int convertedArray[16], int numOfDigits, int minus)
{
    const char baseDigits[16] =
           {'0', '1', '2', '3', '4', '5', '6', '7',
             '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    int nextDigit;
    int spaces = 10 - numOfDigits - minus;

    for (int i = 0; i < spaces; i++)
    {
        printf (" ");
    };

    if (minus == 1)
    {
        printf ("-");
    };

    for (--numOfDigits; numOfDigits >= 0; --numOfDigits)
    {
        nextDigit = convertedArray[numOfDigits];
        printf ("%c", baseDigits[nextDigit]);
    };
}

// Function for multiplying
void scalarMultiply (int nRows, int nCols, int matrix[nRows][nCols], int scalar)
{
    int  row, column;

    for ( row = 0;  row < nRows;  ++row )
        for ( column = 0;  column < nCols;  ++column )
            matrix[row][column]  *=  scalar;
}