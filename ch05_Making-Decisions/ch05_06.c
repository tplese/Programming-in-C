#include <stdio.h>

int main (void)
{
	int number, right_digit;
	int reverse_number = 0;
	
	printf ("Please give me an integer.\n");
	scanf ("%i", &number);
	
	if (number % 10 == 0)
	{
	    printf ("zero ");
	};
	
	for (; number > 0; number /= 10)
	{
	    right_digit = number % 10;
	    reverse_number = (reverse_number * 10) + right_digit;
	};
	
	for (; reverse_number > 0; reverse_number /= 10)
	{
		right_digit = reverse_number % 10;
		
		switch (right_digit)
		{
			case 1:
				printf ("one ");
				break;
			case 2:
				printf ("two ");
				break;
			case 3:
				printf ("three ");
				break;
			case 4:
				printf ("four ");
				break;
			case 5:
				printf ("five ");
				break;
			case 6:
				printf ("six ");
				break;
			case 7:
				printf ("seven ");
				break;
			case 8:
				printf ("eight ");
				break;
			case 9:
				printf ("nine ");
				break;
			default:
				printf ("Sorry, can't read that.");
		};
		
	};
	
	printf ("\n");
	
	return 0;
}