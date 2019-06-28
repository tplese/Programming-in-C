/* If c is a lowercase character, the expression
 *      c – 'a' + 'A'
 *
 * produces the uppercase equivalent of c, assuming an ASCII character set.
 * Write a function called uppercase() that converts all lowercase characters in a string into their uppercase equivalents.
 */

#include <stdio.h>


int main (void)
{
    void askForString (char textString []);
    void printOutString (char bufferString []);
    void uppercase (char textString [], char buffer []);

    printf ("Enter a string of lowercase letters (max 80): ");
    char text [81];
    askForString (text);
    printOutString (text);

    printf ("String in uppercase: ");
    char uppercaseText [81];
    uppercase (text, uppercaseText);
    printOutString (uppercaseText);

    return 0;
}


void askForString (char textString [])
{
    char character;
    int i = 0;

    do
    {
        character = getchar ();
        textString [i] = character;
        i++;
    }
    while (character != '\n');

    textString [i - 1] = '\0';
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


void uppercase (char textString [], char buffer [])
{
    for (int i = 0; textString [i] != '\0'; i++)
    {
        if (textString [i] >= 'a' && textString [i] <= 'z')
        {
            buffer [i] = textString [i] - 'a' + 'A';
        }
        else
        {
            buffer [i] = textString [i];
        };
    };
}