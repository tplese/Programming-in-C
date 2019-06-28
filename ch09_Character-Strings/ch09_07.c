/* Write a function called insertString() to insert one character string into another string.
 * The arguments to the function should consist of the source string, the string to be inserted,
 * and the position in the source string where the string is to be inserted. So, the call
 *      insertString (text, "per", 10);
 *
 * with text as originally defined in the previous exercise (op.a. "the wrong son"), results in
 * the character string "per" being inserted inside text, beginning at text[10].
 * Therefore, the character string "the wrong person" is stored inside the text array after the function returned.
 */

#include <stdio.h>

int main (void)
{
    void printOutText (char text []);
    void askString (char userString []);
    int askStart (void);
    void insertString (char sourceString [], char userString [], int startPoint);

    printf ("Source text: ");
    char source [] = "There is nothing permanent except change.";
    printOutText (source);

    printf ("String you want inserted: ");
    char insert [81];
    askString (insert);

    printf ("Where do you want it inserted (0 - 41): ");
    int start = askStart ();

    insertString (source, insert, start);

    printf ("Resulting text: ");
    printOutText (source);

    return 0;
}


void printOutText (char text [])
{
    int i = 0;

    while (text [i] != '\0')
    {
        printf ("%c", text [i]);
        i++;
    };

    printf ("\n");
}


void askString (char userString [])
{
    char character;
    int i = 0;

    do
    {
        character = getchar ();
        userString [i] = character;
        i++;
    }
    while (character != '\n');

    userString [i - 1] = '\0';
}


int askStart (void)
{
    int startPoint;

    do
    {
        scanf ("%i", &startPoint);
        while (getchar () != '\n');
    }
    while (startPoint < 0 && startPoint > 80);

    return startPoint;
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


int stringLength (char stringToMeasure [])
{
    int i = 0;
    while (stringToMeasure [i] != '\0')
    {
        i++;
    };

    return i;
}


void makeSpaceInSource (char sourceText [], int startIndex, int placesToMove)
{
    int stringLength (char stringToMeasure []);

    int sourceStringLength = stringLength (sourceText);

    for (int i = sourceStringLength; i >= startIndex; i--)
    {
        sourceText [i + placesToMove] = sourceText [i];
    };
}