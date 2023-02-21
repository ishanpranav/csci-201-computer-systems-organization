#include <stdio.h>
#include "list_node.h"

/**
 * The main entry point for the application.
 *
 * @return An exit code. This value is 0 if all assertions succeed.
 */
int main()
{
    struct ListNode first = {"third", 0};
    struct ListNode second = {"second", 0};
    struct ListNode third = {"first", 0};
    struct ListNode fourth = {"****", 0};
    struct ListNode *head = &first;

    list_node_push(&second, &head);
    list_node_push(&third, &head);
    list_node_push(&fourth, &head);
    list_node_shift(&head);

    struct ListNode *current;

    for (current = head; current != NULL; current = current->next)
    {
        printf("%s\t", current->word);
    }

    printf("\n");

    return 0;
}
