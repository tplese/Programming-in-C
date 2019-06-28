/* Write a function called removeString() to remove a specified number of characters from a character string.
 * The function should take three arguments: the source string, the starting index number in the source string,
 * and the number of characters to remove.
 * So, if the character array text contains the string "the wrong son", the call
 *      removeString (text, 4, 6);
 *
 * has the effect of removing the characters “wrong” (the word “wrong” plus the space that follows) from the array text.
 * The resulting string inside text is then "the son".
 */

#include <stdio.h>


int main (void)
{
    void printOutSource (char sourceText []);
    int getNumber (int startOrCount);
    void removeString (char sourceText [], int startChar, int numOfChars);

    printf ("This program cuts out piece of source text. You give starting point and number of characters to be cut out.\n\n");

    char source [] = "True ignorance is not the absence of knowledge, but the refusal to acquire it.";

    printf ("Source text: ");
    printOutSource (source);

    int start = getNumber (1);
    int count = getNumber (2);

    removeString (source, start, count);

    printf ("Text without cut section:  ");
    printOutSource (source);

    return 0;
}


void printOutSource (char sourceText [])
{
    int i = 0;

    while (sourceText [i] != '\0')
    {
        printf ("%c", sourceText [i]);
        i++;
    };

    printf ("\n");
}



int getNumber (int startOrCount)
{
    int userNumber = 0;

    do
    {
        if (startOrCount == 1)
        {
            printf ("From where to start cutting (0 - 77):   ");
        }
        else if (startOrCount == 2)
        {
            printf ("How many characters to take (0 - 77):   ");
        };
        scanf ("%i", &userNumber);
        while (getchar () != '\n');
    }
    while (userNumber < 0 && userNumber > 77);

    return userNumber;
}


void removeString (char sourceText [], int startChar, int numOfChars)
{
    int countRemaining (int start, char text []);

    int remainingChars = countRemaining (startChar, sourceText);

    //int i;

    if (remainingChars >= numOfChars)
    {
        for (;sourceText [startChar + numOfChars] != '\0'; startChar++)
        {
            sourceText [startChar] = sourceText [startChar + numOfChars];
        };

        sourceText [startChar] = '\0';
    }
    else
    {
        sourceText [startChar + 1] = '\0';
    };
}


int countRemaining (int start, char text [])
{
    int count = 0;


    while (text [count] != '\0')
    {
        count++;
    };

    return count - 1;
}