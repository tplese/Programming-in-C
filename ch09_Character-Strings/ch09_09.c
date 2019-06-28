/* You can extend even further the usefulness of the replaceString() function from the preceding exercise if you have it
 * return a value that indicates whether the replacement succeeded, which means that the string to be replaced was found
 * inside the source string. So, if the function returns true if the replacement succeeds and false if it does not, the loop
 *      do
 *          stillFound = replaceString (text, " ", "");
 *      while  ( stillFound );
 *
 * could be used to remove all blank spaces from text, for example.
 * Incorporate this change into the replaceString() function and try it with various character strings to ensure
 * that it works properly.
 */

#include <stdio.h>
#include <stdbool.h>

int main (void)
{
    void askForString (char bufferString []);
    void printOutString (char bufferString []);
    bool replaceString(char sourceString [], char string1 [], char string2 []);

    printf ("ORIGINAL STRING: ");
    char source [] = "There is nothing wrong in change, if it is in the right direction. \
To improve is to change, so to be perfect is to have changed often.";
    printOutString (source);
    printf ("\n");

    printf ("Which part you want replaced? ");
    char s1 [81];
    askForString (s1);

    printf ("What do you want to replace it with? ");
    char s2 [81];
    askForString (s2);

    bool stillFound = replaceString(source, s1, s2);

    if (stillFound)
    {
        do
        {
            stillFound = replaceString(source, s1, s2);
        }
        while (stillFound);

        printf ("AFTER REPLACEMENT: ");
        printOutString (source);
    }
    else
    {
        printf ("String you're looking for is NOT IN ORIGINAL.\n");
    };

    return 0;
}


void askForString (char bufferString [])
{
    char character;
    int i = 0;

    do
    {
        character = getchar ();
        bufferString [i] = character;
        i++;
    }
    while (character != '\n');

    bufferString [i - 1] = '\0';
}


void printOutString (char bufferString [])
{
    int i = 0;

    while (bufferString [i] != '\0')
    {
        printf ("%c", bufferString [i]);
        i++;
    };

    printf ("\n");
}



bool replaceString(char sourceString [], char string1 [], char string2 [])
{
    int findString (char sourceText [], char search []);
    int stringLength (char stringToMeasure []);
    void removeString (char sourceText [], int startChar, int numOfChars);
    void insertString (char sourceString [], char userString [], int startPoint);

    int startPosition = findString (sourceString, string1);
    int searchTermLength = stringLength (string1);

    if (startPosition >= 0)
    {
        removeString (sourceString, startPosition, searchTermLength);
        insertString (sourceString, string2, startPosition);
        return true;
    }
    else
    {
        return false;
    };
}


int findString (char source [], char search [])
{
    int i = 0;
    int j;
    int k;
    bool matching = false;

    // Search for 1st letter match
    while (source [i] != '\0')
    {
        j = 0;

        if (source [i] == search [j])
        {
            k = i;

            while (search [j] != '\0')
            {
                if (source[k] == search [j])
                {
                    matching = true;
                }
                else
                {
                    matching = false;
                    break;
                };

                k++;
                j++;
            };
        };

        if (matching)
            {
                return i;
            };

        i++;
    };

    return -1;
}


int stringLength (char stringToMeasure [])
{
    int i = 0;
    while (stringToMeasure [i] != '\0')
    {
        i++;
    };

    return i;
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


void insertString (char sourceString [], char userString [], int startPoint)
{
    int stringLength (char stringToMeasure []);
    void makeSpaceInSource (char sourceText [], int startIndex, int placesToMove);

    int userStringLength = stringLength (userString);

    makeSpaceInSource (sourceString, startPoint, userStringLength);

    for (int i = 0; userString [i] != '\0'; i++)
    {
        sourceString [startPoint + i] = userString [i];
    };
}





void makeSpaceInSource (char sourceText [], int startIndex, int placesToMove)
{
    int stringLength (char stringToMeasure []);

    int sourceStringLength = stringLength (sourceText);

    sourceText [sourceStringLength + 1] = '\0';

    for (int i = sourceStringLength; i >= startIndex; i--)
    {
        sourceText [i + placesToMove] = sourceText [i];
    };

}