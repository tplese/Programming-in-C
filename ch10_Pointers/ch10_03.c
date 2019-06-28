/* The function developed in exercise 2 only inserts an element after an existing element in the list, thereby preventing you
 * from inserting a new entry at the front of the list. How can you use this same function and yet overcome this problem?
 * (Hint: Think about setting up a special structure to point to the beginning of the list.)
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
    struct entry * insertEntry (struct entry *inserted_elem, struct entry *list_start);
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

    struct entry insert;
    insert.value = 999;
    insert.next = &n1;

    printf ("After insert: ");
    list_pointer = insertEntry (&insert, list_pointer);
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


struct entry * insertEntry (struct entry *inserted_elem, struct entry *list_start)
{
    list_start = inserted_elem;

    return list_start;
};