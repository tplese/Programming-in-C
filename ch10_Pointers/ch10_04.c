/* Write a function called removeEntry() to remove an entry from a linked list. The sole argument to the procedure should be
 * a pointer to the list. Have the function remove the entry after the one pointed to by the argument.
 * (Why can’t you remove the entry pointed to by the argument?)
 * You need to use the special structure you set up in exercise 3 to handle the special case of removing
 * the first element from the list.
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
    struct entry * removeEntry (struct entry *node_to_change);

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

    printf ("Which element do you want removed? (1-4) ");
    int remove_this;
    scanf ("%i", &remove_this);

    switch (remove_this)
    {
        case 1:
            list_pointer = n1.next;
            break;
        case 2:
            n1.next = removeEntry (n1.next);
            break;
        case 3:
            n2.next = removeEntry (n2.next);
            break;
        case 4:
            n3.next = removeEntry (n3.next);
            break;
    };

    printf ("After removal: ");
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


struct entry * removeEntry (struct entry *node_to_change)
{
    node_to_change = node_to_change->next;

    return node_to_change;
};