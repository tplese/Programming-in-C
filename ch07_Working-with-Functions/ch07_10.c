// Write a function prime() that returns 1 if its argument is a prime number and returns 0 otherwise.

#include <stdio.h>

int main (void)
{
    int askForNumber ();
    int prime (int x);

    int userNumber;
    int primeResult;

    // Continues program operation until user enters 0 for exit
    do
    {
        userNumber = askForNumber ();

        // Doing calculations only if user's number is greater than 1
        if (userNumber == 1)
        {
            printf ("1 is not considered as a prime number.\n");
        }
        else if (userNumber > 1)
        {
            primeResult = prime (userNumber);
        };

        // Notifying user if his number is prime or not
        if (primeResult == 1 && userNumber > 1)
        {
            printf ("%i => PRIME number\n", userNumber);
        }
        else if (primeResult == 0 && userNumber > 1)
        {
            printf ("%i => NOT prime number\n", userNumber);
        };
    }
    while (userNumber != 0);

    return 0;
}


// Gets a number from user for testing if it's a prime number
int askForNumber ()
{
    int userNumber = -1;

    do
    {
        printf ("Enter integer 1 to 32767 (zero for exit): ");
        scanf ("%i", &userNumber);
        while (getchar() != '\n');
    }
    while (userNumber < 0 || userNumber > 32767);

    return userNumber;
}


// Tests if user's number is a prime number by going through array of previously generated prime numbers
int prime (int x)
{
    int populatePrimesArray (int userNumber, int primes [3512]);

    int primeHits;
    int primes [3512];

    primeHits = populatePrimesArray (x, primes);
    //printf("primeHits = %i\n", primeHits);

    for (int i = 0; i < primeHits; i++)
    {
        if (x % primes [i] == 0)
        {
            return 0;
        };
    };

    return 1;
}


// Generates prime numbers up to the number that user provided and stores them in an array
int populatePrimesArray (int userNumber, int primes [3512])
{
    int primeHits = 0;
    primes [0] = 2;

    for (int testedNumber = 3; testedNumber <= userNumber; testedNumber++)
    {

        for (int primesOrdinal = 0; primesOrdinal <= primeHits; primesOrdinal++)
        {
            if (testedNumber % primes[primesOrdinal] == 0)
            {
                break;
            };

            if (primesOrdinal == primeHits)
            {
                primesOrdinal++;
                primes[primesOrdinal] = testedNumber;
                primeHits = primesOrdinal;
                //printf ("primes[%i] = %i\n", primesOrdinal, primes [primesOrdinal]);
            };
        };
    };

    return primeHits;
}