/* Write a function called insertEntry() to insert a new entry into a linked list. Have the procedure take as arguments
 * a pointer to the list entry to be inserted (of type struct entry as defined in this chapter), and a pointer to an element
 * in the list after which the new entry is to be inserted.
 */

#include <stdio.h>

struct entry
{
    int value;
    struct entry *next;
};

int main (void)
{
    void printout (struct entry *list_start);
    struct entry * insertEntry (struct entry *insert_element, struct entry *point_of_insert);

    struct entry n1, n2, n3, n4;
    struct entry *list_pointer = &n1;

    n1.value = 100;
    n1.next = &n2;
    n2.value = 200;
    n2.next = &n3;
    n3.value = 300;
    n3.next = &n4;
    n4.value = 400;
    n4.next = (struct entry *) 0;

    printf ("Original list: ");
    printout (list_pointer);

    struct entry insert = {999, &n4};

    printf ("After insert: ");
    n3.next = insertEntry (&insert, n3.next);
    printout (list_pointer);

    return 0;
}


void printout (struct entry *list_start)
{
    while (list_start)
    {
        printf ("%i ", list_start->value);
        list_start = list_start->next;
    };
    printf ("\n");
};


struct entry * insertEntry (struct entry *insert_element, struct entry *point_of_insert)
{
    point_of_insert = insert_element;

    return point_of_insert;
};