#include <stdio.h>

/**
 * Represents a linked-list node.
*/
struct node
{
    char *word;
    struct node *next;
};

/**
 * Adds a node to the front of a linked list.
 * 
 * @param node a pointer to a node.
 * @param head a pointer to the head of a linked-list (itself a pointer to a
 *             node). 
*/
void addFront(struct node *node, struct node **head)
{
    node->next = *head;
    *head = node;
}

/**
 * Reverses the elements of the linked list.
 *
 * @param head a pointer to the head of a linked-list (itself a pointer to a
 *             node). 
 */
void reverse(struct node **head)
{
    if (head == NULL)
    {
        return;
    }

    struct node *current = *head;

    if (current == NULL)
    {
        return;
    }

    struct node *previous = NULL;

    // *[A] -> [B] -> [C] -> [D] -> [E]

    // 1. *[A]
    //     [B] -> [C] -> [D] -> [E]

    // 2. [B] -> *[A]
    //    [C]  -> [D] -> [E]

    // 3. [C] -> [B] -> *[A]
    //    [D] -> [E]

    // 4. [D] -> [C] -> [B] -> *[A]
    ///   [E]

    // 5. [E] -> [D] -> [C] -> [B] -> *[A]

    while (current != NULL)
    {
        struct node *next = current->next;

        current->next = previous;
        previous = current;
        current = next;
    }

    // *[E] -> [D] -> [C] -> [B] -> [A]

    *head = previous;
}

/**
 * Prints a textual representation of a linked-list to the standard output
 * stream.
 * 
 * @param current a pointer to the node from which to begin printing the list. 
*/
void printNodes(struct node *current)
{
    while (current != 0)
    {
        printf("%s ", current->word);
        current = current->next;
    }

    printf("\n");
}

/**
 * Swaps the middle two elements of a linked list.
 *
 * @param head a pointer to the head of a linked-list (itself a pointer to a
 *             node). 
 */
void swapMiddle(struct node **head)
{
    if (head == NULL)
    {
        return;
    }

    // Step 1: Find the middle element

    //  Floyd's cycling finding algorithm: technique to find the middle
    //  The 'slow' pointer iterates over every node; the 'fast' pointer
    //  iterates over every other node. When the 'fast' (current) pointer
    //  reaches the end, the 'slow' (middleRight) pointer must have reached
    //  the middle (or the value to the right of it).

    struct node *middleLeft = NULL;
    struct node *middleRight = *head;
    struct node *current = *head;

    if (middleRight == NULL || current == NULL)
    {
        return;
    }

    while (current != NULL && current->next != NULL)
    {
        middleLeft = middleRight;
        middleRight = middleRight->next;
        current = current->next->next;
    }

    // Step 2: Swap the middle elements (left and right)

    if (middleLeft == NULL)
    {
        // *[middleRight] -> [middleRight.next] ...

        //  [middleRight]
        // *[middleRight.next] ...

        *head = middleRight->next;
    }
    else
    {
        // ... -> [middleLeft] -> [middleRight] -> [middleRight.next] -> [next] ...

        // [middleRight]
        // ... -> [middleLeft] -> [middleRight.next] -> [next] ...

        middleLeft->next = middleRight->next;
    }

    // ... -> [middleRight] -> [middleLeft] -> [middleRight.next] -> [next]

    middleRight->next = middleLeft;
}

/**
 * The main entry point for the application.
 *
 * @return An exit code. This value is 0 if all assertions succeed.
 */
int main()
{
    struct node *head = NULL;
    struct node n1 = {"1", NULL};
    struct node n2 = {"2", NULL};
    struct node n3 = {"3", NULL};
    struct node n4 = {"4", NULL};
    struct node n5 = {"5", NULL};
    struct node n6 = {"6", NULL};

    addFront(&n1, &head);
    addFront(&n2, &head);
    addFront(&n3, &head);
    addFront(&n4, &head);
    addFront(&n5, &head);
    addFront(&n6, &head);
    printf("Values: ");
    printNodes(head);
    reverse(&head);
    printf("Reversed: ");
    printNodes(head);
    reverse(&head);
    printf("Reversed again (original): ");
    printNodes(head);
    printf("Swap middle: ");
    swapMiddle(&head);
    printNodes(head);
    swapMiddle(&head);
    printf("Swap middle again (original): ");
    printNodes(head);

    return 0;
}
