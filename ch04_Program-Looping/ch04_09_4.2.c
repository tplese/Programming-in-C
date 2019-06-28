/* Program to calculate the 200th triangular number 
Introduction of the for statement */ 

#include <stdio.h> 
int main (void) 
{ 
    int triangularNumber = 0; 
    int n = 1;
    
    while (n <= 200)
    {
        triangularNumber = triangularNumber + n;
        n = n + 1;
    }
    
    printf ("The 200th triangular number is %i\n", triangularNumber); 
    
    return 0; 
    
}