/* Develop insertEntry() and removeEntry() functions for a doubly linked list that are similar in function to those developed in previous exercises for a singly linked list.
 * Why can your removeEntry() function now take as its argument a direct pointer to the entry to be removed from the list?
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
    void printout (struct entry * start, int direction);
    void insertEntry (struct entry *previous_elem, struct entry *inserted_elem, struct entry *next_elem);
    void removeEntry (struct entry * start_pointer, int match, int direction);

    struct entry n1, n2, n3, n4, n5;

    n1.value = 100;
    n1.preceding = (struct entry *) 0;
    n1.next = &n2;

    n2.value = 200;
    n2.preceding = &n1;
    n2. next = &n3;

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
    struct entry * list_pointer;
    list_pointer = &n1;
    printout (list_pointer, 1);

    printf ("List backward: ");
    list_pointer = &n5;
    printout (list_pointer, 2);

    // ************ INSERT NEW ELEMENT ************
    printf ("Number to be inserted: ");
    struct entry element;
    scanf ("%i", &element.value);

    printf ("Ascending=1 OR Descending=2 ? ");
    int ascend_descend;
    scanf ("%i", &ascend_descend);

    printf ("Position to insert? (1-6) ");
    int placement;
    scanf ("%i", &placement);

    if (ascend_descend == 1)
    {
        list_pointer = &n1;

        switch (placement)
        {
            case 1:
                element.preceding = n1.preceding;
                n1.preceding = &element;
                element.next = list_pointer;
                list_pointer = &element;
                break;
            case 2:
                insertEntry (&n1, &element, &n2);
                break;
            case 3:
                insertEntry (&n2, &element, &n3);
                break;
            case 4:
                insertEntry (&n3, &element, &n4);
                break;
            case 5:
                insertEntry (&n4, &element, &n5);
                break;
            case 6:
                element.preceding = &n5;
                element.next = n5.next;
                n5.next = &element;
                break;
            default:
                printf ("Error: Placement accepts only numbers 1-6!");
        };
    }
    else if (ascend_descend == 2)
    {
        list_pointer = &n5;

        switch (placement)
        {
            case 1:
                element.preceding = list_pointer;
                list_pointer = &element;
                element.next = n5.next;
                n5.next = &element;
                break;
            case 2:
                insertEntry (&n4, &element, &n5);
                break;
            case 3:
                insertEntry (&n3, &element, &n4);
                break;
            case 4:
                insertEntry (&n2, &element, &n3);
                break;
            case 5:
                insertEntry (&n1, &element, &n2);
                break;
            case 6:
                element.preceding = n1.preceding;
                n1.preceding = &element;
                element.next = &n1;
                break;
            default:
                printf ("Error: Placement accepts only numbers 1-6!");
        };
    }
    else
    {
        printf ("Error: Ascend/Descend can only be 1 or 2!");
    };

    printf ("After INSERTION: ");
    printout (list_pointer, ascend_descend);


    // ************ REMOVE EXISTING ELEMENT ************
    printf ("Which element do you want removed? (1-6) ");
    int remove_this;
    scanf ("%i", &remove_this);

    removeEntry (list_pointer, remove_this, ascend_descend);

    printf ("After REMOVAL: ");
    printout (list_pointer, ascend_descend);

    return 0;
}

void printout (struct entry * start, int direction)
{
    if (direction == 1)
    {
        while (start)
        {
            printf ("%i ", start->value);
            start = start->next;
        };
    }
    else if (direction == 2)
    {
        while (start)
        {
            printf ("%i ", start->value);
            start = start->preceding;
        };
    }
    else
    {
        printf ("Something went wrong!");
    };

    printf ("\n");
}

void insertEntry (struct entry *previous_elem, struct entry *inserted_elem, struct entry *next_elem)
{
    (*inserted_elem).preceding = (*next_elem).preceding;
    (*next_elem).preceding = inserted_elem;
    (*inserted_elem).next = (*previous_elem).next;
    (*previous_elem).next = inserted_elem;
}


void removeEntry (struct entry * start_pointer, int match, int direction)
{
    struct entry *pre_element;
    struct entry *post_element;

    if (direction == 1)
    {

        if (start_pointer->value == match) // for value in position 1 in the lsit
        {
            post_element = start_pointer->next;
            *start_pointer = *post_element;
            post_element->preceding = start_pointer;
        }
        else // for values in positions 2-6 in the list
        {
            while (start_pointer)
            {
                if (start_pointer->next == '\0' && start_pointer->value == match) // position 6 (last)
                {
                    pre_element = start_pointer->preceding;
                    pre_element->next = start_pointer->next;

                    start_pointer = start_pointer->next;
                }
                else if (start_pointer->value == match) // positions 2-5
                {
                    pre_element = start_pointer->preceding;
                    post_element = start_pointer->next;

                    (*pre_element).next = (*start_pointer).next;
                    (*post_element).preceding = (*start_pointer).preceding;

                    start_pointer = start_pointer->next;
                }
                else if (start_pointer->next == '\0' && start_pointer->value != match)
                {
                    printf ("That entry does not exits in the list.\n");
                    start_pointer = start_pointer->next;
                }
                else
                {
                    start_pointer = start_pointer->next;
                };
            };
        };
    }
    else if (direction == 2)
    {
        if (start_pointer->value == match) // for value in position 1 in the lsit
        {
            pre_element = start_pointer->preceding;
            *start_pointer = *pre_element;
            pre_element->next = start_pointer;
        }
        else // for values in positions 2-6 in the list
        {
            while (start_pointer)
            {
                if (start_pointer->preceding == '\0' && start_pointer->value == match) // position 6 (last)
                {
                    post_element = start_pointer->next;
                    post_element->preceding = start_pointer->preceding;

                    start_pointer = start_pointer->preceding;
                }
                else if (start_pointer->value == match) // positions 2-5
                {
                    pre_element = start_pointer->preceding;
                    post_element = start_pointer->next;

                    (*pre_element).next = (*start_pointer).next;
                    (*post_element).preceding = (*start_pointer).preceding;

                    start_pointer = start_pointer->next;
                }
                else if (start_pointer->preceding == '\0' && start_pointer->value != match)
                {
                    printf ("That entry does not exits in the list.\n");
                    start_pointer = start_pointer->next;
                }
                else
                {
                    start_pointer = start_pointer->preceding;
                };
            };
        };
    }
    else
    {
        printf ("Error: in remove fuction\n");
    };
}