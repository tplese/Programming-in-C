/* Rewrite the readLine() function from Chapter 9 so that it uses a character pointer rather than an array.
 *

#include <stdio.h>

int main (void)
{
    int   i;
    char  line[81];
    void  readLine (char  buffer[]);

    for ( i = 0; i < 3; ++i )
    {
        readLine (line);
        printf ("%s\n\n", line);
    }

    return 0;
}

// Function to read a line of text from the terminal

void  readLine (char  buffer[])
{
    char  character;
    int   i = 0;

    do
    {
        character = getchar ();
        buffer[i] = character;
        ++i;
    }
    while ( character != '\n' );

    buffer[i - 1] = '\0';
}
 *
 */

#include <stdio.h>

int main (void)
{
    int   i;
    char  line[81];
    void  readLine (char *buffer);

    for ( i = 0; i < 3; ++i )
    {
        readLine (line);
        printf ("%s\n\n", line);
    }

    return 0;
}

// Function to read a line of text from the terminal

void  readLine (char *buffer)
{
    char  character;

    do
    {
        character = getchar ();
        *buffer = character;
        ++buffer;
    }
    while ( character != '\n' );

    *(buffer - 1) = '\0';
}