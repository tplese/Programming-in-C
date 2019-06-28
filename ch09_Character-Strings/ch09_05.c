/* Write a function called findString() to determine if one character string exists inside another string.
 * The first argument to the function should be the character string that is to be searched and
 * the second argument is the string you are interested in finding.
 * If the function finds the specified string, have it return the location in the source string where the string was found.
 * If the function does not find the string, have it return −1. So, for example, the call
 *      index = findString ("a chatterbox", "hat");
 *
 * searches the string "a chatterbox" for the string "hat". Because "hat" does exist inside the source string,
 * the function returns 3 to indicate the starting position inside the source string where "hat" was found.
 */

#include <stdio.h>
#include <stdbool.h>


int main (void)
{
    void getSearchTerm (char buffer []);
    int findString (char source [], char search []);

    char sourceText [] = "A quote from Ken Baldwin, a survivor, about what happened the moment he jumped: 'I instantly realized that everything in my life that I’d thought was unfixable was totally fixable—except for having just jumped.'";
    //char sourceText [] = "twenty-two";
    char searchTerm [81];

    printf ("This is source Text: %s\n", sourceText);

    printf ("Type in the search term:   ");
    getSearchTerm (searchTerm);

    int index = findString (sourceText, searchTerm);

    if (index >= 0)
    {
        printf ("Your search term was found in the source text on position %i.\n", index);
    }
    else if (index == -1)
    {
        printf ("Your search term does not exist in source text.\n");
    }
    else
    {
        printf ("Something went wrong.");
    };

    return 0;
}


void getSearchTerm (char buffer [])
{
    char character;
    int i = 0;

    do
    {
        character = getchar ();
        buffer [i] = character;
        i++;
    }
    while (character != '\n');

    buffer [i - 1] = '\0';
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