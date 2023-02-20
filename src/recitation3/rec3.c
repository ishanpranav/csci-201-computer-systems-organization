#include <stdio.h>

/**
 * Represents a linked-list node.
 */
struct node
{
    /**
     * Specifies the node value, a pointer to a zero-terminated string.
     */
    char *word;

    /**
     * Specifies the next node in the linked list. This value is 0 if the node
     * is the tail of the linked list.
     */
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
    //  Floyd's cycle-finding algorithm: technique to find the middle
    //  The 'slow' pointer iterates over every node; the 'fast' pointer
    //  iterates over every other node. When the 'fast' pointer reaches
    //  the end, the 'slow'  pointer must have reached the middle.
    
    struct node *slow = *head;
    struct node *fast = *head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // There are an odd number of nodes

    if (fast == NULL)
    {
        return;
    }

    // Find the previous node

    struct node *previous = *head;
    struct node *current = *head;

    while (current != slow)
    {
        previous = current;
        current = current->next;
    }

    // Perform the swap
    
    struct node *next = current->next;
    
    current->next = slow->next;
    slow->next = next;
    previous->next = slow;
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
