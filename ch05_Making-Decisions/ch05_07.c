// Program to generate a table of prime numbers 

#include <stdio.h> 

int main (void) 
{ 
	int p, d; 
	_Bool isPrime;

    printf ("1 2 ");
    
	for (p = 3; p <= 50; ++p) 
	{ 
		isPrime = 1;
		
		if (p % 2 != 0)
		{
    		for (d = 3; d < p && isPrime == 1; ++d)
    		{
    		    if (d % 2 != 0)
    		    {
    		        if (p % d == 0)
    		        {
    		            isPrime = 0;
    		        };
    		    };
    		};
		}
    	else
    	{
    	    isPrime = 0;
    	};
    			
    	if (isPrime != 0)
    	{
    	    printf ("%i ", p);
    	};
	};
	
	printf ("\n"); 
	
	return 0;
}