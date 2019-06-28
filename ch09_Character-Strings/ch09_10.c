/* Write a function called dictionarySort() that sorts a dictionary, as defined in Programs 9.9 and 9.10, into alphabetical order.
*/

#include <stdio.h>

struct entry
{
    char  word[15];
    char  definition[50];
};


int main (void)
{
    void printOutStruct (struct entry dictionary[], const int entries);
    void dictionarySort (struct entry dictionary[], const int entries);

    struct entry  dictionary[100] =
       {
           { "aigrette", "an ornamental cluster of feathers" },
           { "aardvark", "a burrowing African mammal"        },
           { "acumen",   "mentally sharp; keen"              },
           { "abyss",    "a bottomless pit"                  },
           { "addle",    "to become confused"                },
           { "ajar",     "partially opened"                  },
           { "affix",    "to append; attach"                 },
           { "agar",     "a jelly made from seaweed"         },
           { "ahoy",     "a nautical call of greeting"       },
           { "aerie",    "a high nest"                       }
       };

    int   entries = 10;
    char  word[15];
    int   entry;

    printf ("ORIGINAL ORDER:\n");
    printOutStruct (dictionary, entries);

    dictionarySort (dictionary, entries);

    printf ("SORTED ORDER:\n");
    printOutStruct (dictionary, entries);

    return 0;
}


void printOutStruct (struct entry dictionary[], const int entries)
{
    int i = 0;

    while (i < entries)
    {
        printf ("%s\t\t%s\n", dictionary[i].word, dictionary[i].definition);
        i++;
    };

    printf ("\n");
}


void dictionarySort (struct entry dictionary[], const int entries)
{
    int compareStrings (const char s1[], const char s2[]);
    int result;

    struct entry temporary[100];

    for (int i = 0; i < entries - 1; i++)
    {
        for (int j = i + 1; j < entries; j++)
        {
            result = compareStrings (dictionary[i].word, dictionary[j].word);

            if (result == 1)
            {
                temporary[i] = dictionary[i];
                dictionary[i] = dictionary[j];
                dictionary[j] = temporary[i];
            };
        };
    };
}


// Function to compare two character strings
int  compareStrings (const char  s1[], const char  s2[])
{
    int  i = 0, answer;

    while (s1[i] == s2[i] && s1[i] != '\0'&& s2[i] != '\0' )
        ++i;

    if ( s1[i] < s2[i] )
        answer = -1;               /* s1 < s2  */
    else if ( s1[i] == s2[i] )
        answer = 0;                 /* s1 == s2 */
    else
        answer = 1;                 /* s1 > s2  */

    return answer;
}