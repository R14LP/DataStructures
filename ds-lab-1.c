#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

void addFront(struct node **head, int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = *head;
    *head = temp;
}

struct node *addLast (struct node *head, int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;

    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = temp;
    temp->next = NULL;
}

void printList(struct node *head)
{
    while (head != NULL)
    {
        printf("data: %d\n", head->data);
        head = head->next;
    }
}

void printListRecursive(struct node *head)
{
    if(head == NULL)
        return;
    printf("data: %d\n", head->data);
    printListRecursive(head->next);
}


int main()
{
    struct node *head = NULL;

    addFront(&head, 2);
    addLast(&head, 3);
    addFront(&head, 4);
    printListRecursive(head);
    return 0;
}