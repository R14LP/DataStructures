#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

void insertAtEnd(struct node** head, int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if(newNode == NULL)
        return;
    newNode->data = value;
    newNode->next = NULL;

    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct node *tempNode = *head;
    while(tempNode->next != NULL)
    {
        tempNode = tempNode->next;
    }
    tempNode->next = newNode;
}

void insertAtBeginning(struct node** head, int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if(newNode == NULL)
        return;
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct node* head)
{
    while(head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void Deletion(struct node** head, int value)
{
    struct node *temp = *head;
    struct node *prev = NULL;

    if(temp != NULL && temp->data == value)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

int main()
{
    int selection = 0;
    struct node *head = NULL;
    struct node *tail = NULL;

    for (int i = 0; i < 5; i++)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        
        printf("\nEnter the %d. data: ", i + 1);
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }else
        {
            tail->next = newNode;
            tail = newNode;
        }
        
    }
    while(selection != -1)
    {
        printf("\n(1-printList) (2-insertEnd) (3-insertBeginning) (4-delete)");
        printf("\nMake your selection: ");
        scanf("%d", &selection);

        switch (selection)
        {
        case 1:
            printList(head);
            break;

        case 2:
            int insertAtEndData;
            printf("\nEnter the data you wanna add: ");
            scanf("%d", &insertAtEndData);
            insertAtEnd(&head, insertAtEndData);
            break;
        
        case 3:
            int insertAtBeginningData;
            printf("\nEnter the data you wanna add: ");
            scanf("%d", &insertAtBeginningData);
            insertAtBeginning(&head, insertAtBeginningData);
            break;
        case 4:
            int deleteData;
            printf("\nEnter the data you wanna delete: ");
            scanf("%d", &deleteData);
            Deletion(&head, deleteData);
        default:
            break;
        }
    }
    return 0;
}