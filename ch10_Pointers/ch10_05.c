/* A doubly linked list is a list in which each entry contains a pointer to the preceding entry in the list as well as a pointer
 * to the next entry in the list. Define the appropriate structure definition for a doubly linked list entry and then
 * write a small program that implements a small doubly linked list and prints out the elements of the list.
 */

#include <stdio.h>

struct entry
{
    int value;
    struct entry * preceding;
    struct entry * next;
};

int main (void)
{
    void printout (struct entry *list_start, int direction);

    struct entry n1, n2, n3, n4, n5;
    struct entry *list_pointer;

    n1.value = 100;
    n1.preceding = (struct entry *) 0;
    n1.next = &n2;

    n2.value = 200;
    n2.preceding = &n1;
    n2.next = &n3;

    n3.value = 300;
    n3.preceding = &n2;
    n3.next = &n4;

    n4.value = 400;
    n4.preceding = &n3;
    n4.next = &n5;

    n5.value = 500;
    n5.preceding = &n4;
    n5.next = (struct entry *) 0;

    printf ("List forward: ");
    list_pointer = &n1;
    printout (list_pointer, 1);

    printf ("List backward: ");
    list_pointer = &n5;
    printout (list_pointer, 2);

    return 0;
}


void printout (struct entry *list_start, int direction)
{
    if (direction == 1)
    {
        while (list_start)
        {
            printf ("%i ", list_start->value);
            list_start = list_start->next;

        };
    }
    else if (direction == 2)
    {
        while (list_start)
        {
            printf ("%i ", list_start->value);
            list_start = list_start->preceding;
        };
    }
    else
    {
        printf ("Error\n");
    };

    printf ("\n");
};