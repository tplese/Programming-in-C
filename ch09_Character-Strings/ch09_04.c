/* Write a function called substring() to extract a portion of a character string. The function should be called as follows:
 *      substring (source, start, count, result);
 *
 * where
 *      source is the character string from which you are extracting the substring,
 *      start is an index number into source indicating the first character of the substring,
 *      count is the number of characters to be extracted from the source string, and
 *      result is an array of characters that is to contain the extracted substring.
 *
 * For example, the call
 *      substring ("character", 4, 3, result);
 *
 * extracts the substring "act" (three characters starting with character number 4) from the string "character" and places
 * the result in result.
 *
 * Be certain the function inserts a null character at the end of the substring in the result array. Also, have the function
 * check that the requested number of characters does, in fact, exist in the string. If this is not the case, have the
 * function end the substring when it reaches the end of the source string. So, for example, a call such as
 *      substring ("two words", 4, 20, result);
 *
 * should just place the string “words” inside the result array, even though 20 characters were requested by the call.
 */

#include <stdio.h>


int main (void)
{
    void readLine (char buffer[]);
    int getNumber (int startOrCount);
    void substring (char userTxt [], int startChar, int numOfChar, char cutOutTxt []);

    printf ("This program asks you for text input, and where to start the cut and how many characters to take.\n\
Then it prints out charaters chosen to cut.\n\n");

    printf ("Type in text (MAX 80 characters):   ");
    char source [81];
    readLine (source);

    int start = getNumber (1);
    int count = getNumber (2);

    char result [81];

    substring (source, start, count, result);

    printf ("Text that was cut out:  ");
    int i = 0;
    while (result [i] != '\0')
    {
        printf ("%c", result [i]);
        i++;
    };

    printf ("\n");

    return 0;
}


void readLine (char buffer[])
{
    char character;
    int i = 0;

    do
    {
        character = getchar ();
        buffer[i] = character;
        ++i;
    }
    while (character != '\n');

    buffer[i - 1] = '\0';
}


int getNumber (int startOrCount)
{
    int userNumber = 0;

    do
    {
        if (startOrCount == 1)
        {
            printf ("From where to start cutting (1 - 80):   ");
        }
        else if (startOrCount == 2)
        {
            printf ("How many characters to take (1 - 80):   ");
        };
        scanf ("%i", &userNumber);
        while (getchar () != '\n');
    }
    while (userNumber < 1 && userNumber > 80);

    return userNumber;
}


void substring (char userTxt [], int startChar, int numOfChar, char cutOutTxt [])
{
    int i;

    for (i = 0; i < numOfChar && userTxt [startChar + i] != '\0'; i++)
    {
        cutOutTxt [i] = userTxt [startChar + i];
    };

    cutOutTxt [i] = '\0';
}