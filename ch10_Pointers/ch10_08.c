/* Write a function called sort3() to sort three integers into ascending order. (This function is not to be implemented with arrays.)
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
    void printout (struct entry * start);
    //void printout (struct entry * start, int direction);
    void sort3 (struct entry * start);

    struct entry n1, n2, n3;

    n1.value = 135;
    //n1.preceding = (struct entry *) 0;
    n1.next = &n2;

    n2.value = 234;
    //n2.preceding = &n1;
    n2.next = &n3;

    n3.value = 11;
    //n3.preceding = &n2;
    n3.next = (struct entry *) 0;

    printf ("Before sorting: ");
    struct entry * list_pointer = &n1;
    printout (list_pointer);

    sort3 (list_pointer);

    printf ("After sorting: ");
    printout (list_pointer);

    return 0;
}


void printout (struct entry * start)
{
    while (start)
    {
        printf ("%i ", start->value);
        start = start->next;
    };

    printf ("\n");
}


void sort3 (struct entry * start)
{
    struct entry * ptr1, *ptr2;
    int temp;

    for (ptr1 = start; ptr1 != '\0'; ptr1 = ptr1->next)
    {

        for (ptr2 = ptr1->next; ptr2 != '\0'; ptr2 = ptr2->next)
        {
            if (ptr1->value > ptr2->value)
            {
                temp = ptr1->value;
                ptr1->value = ptr2->value;
                ptr2->value = temp;
            };
        };
    };
}