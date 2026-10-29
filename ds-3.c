#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertAtEnd(struct node **head, int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL)
        return;
    newNode->data = value;

    if (*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    struct node *current = *head;
    while (current->next != *head)
        current = current->next;
    current->next = newNode;
    newNode->next = *head;
}

void insertAtBeginning(struct node **head, int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL)
        return;

    newNode->data = value;

    if (*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    struct node *current = *head;
    while (current->next != *head)
        current = current->next;

    newNode->next = *head;
    current->next = newNode;
    *head = newNode;
}

void insertAfter(struct node *head, int value, int target)
{
    if (head == NULL)
        return;

    struct node *current = head;
    do
    {
        if (current->data == target)
        {
            struct node *newNode = malloc(sizeof(struct node));
            if (newNode == NULL)
                return;
            newNode->data = value;
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    } while (current != head);
}

void deleteNode(struct node **head, int value)
{
    if (*head == NULL)
        return;

    struct node *current = *head;
    struct node *previous = NULL;

    do
    {
        if (current->data == value)
            break;
        previous = current;
        current = current->next;
    } while (current != *head);

    if (current->data != value)
        return;

    if (current->next == current)
    {
        *head = NULL;
    }
    else
    {
        if (current == *head)
        {
            previous = *head;
            while (previous->next != *head)
                previous = previous->next;
            *head = current->next;
        }
        previous->next = current->next;
    }
    free(current);
}

void printList(struct node *head)
{
    if (head == NULL)
    {
        printf("NULL\n");
        return;
    }

    struct node *current = head;
    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(head: %d)\n", head->data);
}

void freeList(struct node *head)
{
    if (head == NULL)
        return;

    struct node *current = head->next;
    while (current != head)
    {
        struct node *next = current->next;
        free(current);
        current = next;
    }
    free(head);
}

int main()
{
    struct node *head = NULL;
    int choice = 0;
    int value;
    int target;

    for (int i = 0; i < 5; i++)
    {
        printf("Enter the %d. data: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    while (choice != -1)
    {
        printf("\n(1-print) (2-insertEnd) (3-insertBeginning) (4-insertAfter) (5-delete) (-1-exit)");
        printf("\nMake your selection: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printList(head);
            break;

        case 2:
            printf("Enter the data you want to add: ");
            scanf("%d", &value);
            insertAtEnd(&head, value);
            break;

        case 3:
            printf("Enter the data you want to add: ");
            scanf("%d", &value);
            insertAtBeginning(&head, value);
            break;

        case 4:
            printf("Enter the data you want to add: ");
            scanf("%d", &value);
            printf("Enter the value to insert after: ");
            scanf("%d", &target);
            insertAfter(head, value, target);
            break;

        case 5:
            printf("Enter the data you want to delete: ");
            scanf("%d", &value);
            deleteNode(&head, value);
            break;

        default:
            break;
        }
    }

    freeList(head);
    return 0;
}