/** 2. a) Modify Program 7.4 so the value of triangularNumber is returned by the function.
  * b) Then go back to Program 4.5 and change that program so that it calls the new version
  * of the calculateTriangularNumber() function.
 */

// 4.5 Using Nested for Loops

#include <stdio.h>
#include <ctype.h>
#include <cs50.h>

int askNumber (void);
int calculateTriangularNumber (int userNumber);

int main (void)
{
     int numberToCalculate;

     do
     {
          numberToCalculate = askNumber ();

          if (numberToCalculate >= 1 && numberToCalculate <= 32767)
          {
               printf ("Triangular number %i is %i\n\n", numberToCalculate, calculateTriangularNumber (numberToCalculate));
          };
     }
     while (numberToCalculate != 0);

     return 0;
}

int askNumber (void)
{
     int userEntry = -1;

     printf ("What triangular number do you want? Type 0 (zero) to exit.\n");

     do
     {
          scanf ("%i", &userEntry);

          // reads the buffer characters till the end and discards them(including newline) and using it after the
          // “scanf()” statement clears the input buffer and allows the input in the desired container.
          while ((getchar()) != '\n');

          if (!(userEntry >= 0 && userEntry <= 32767))
          {
               printf ("Please enter number 0 - 32767: \n");
          };
     }
     while (!(userEntry >= 0 && userEntry <= 32767));

     return userEntry;
}

int calculateTriangularNumber (int userNumber)
{
     int triangularNumber = 0;

     for (int i = 1;  i <= userNumber;  ++i)
     {
          triangularNumber += i;
     };

     return triangularNumber;
}