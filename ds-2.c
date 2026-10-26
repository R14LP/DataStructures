#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void insertAtEnd(struct node **head, int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL)
        return;
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct node *current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
    newNode->prev = current;

}

void insertAtBeginning(struct node **head, int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL)
        return;
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void insertAfter(struct node *head, int value, int target)
{
    struct node *current = head;
    while (current != NULL && current->data != target)
        current = current->next;

    if (current == NULL)
        return;

    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL)
        return;
    newNode->data = value;
    newNode->next = current->next;
    current->next = newNode;
}

void deleteNode(struct node **head, int value)
{
    struct node *current = *head;
    struct node *previous = NULL;

    if (current != NULL && current->data == value)
    {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->data != value)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
        return;
    previous->next = current->next;
    free(current);
}

void printList(struct node *head)
{
    while (head != NULL)
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(struct node *head)
{
    while (head != NULL)
    {
        struct node *next = head->next;
        free(head);
        head = next;
    }
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