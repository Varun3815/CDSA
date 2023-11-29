#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head, *tail;

void insertAtBegin(int);
void insertAtEnd(int);
void displayList();
void insertAfterElement(int, int);

int main()
{
    int choice, data, position;
    while (1)
    {
        printf("to add data in begin press          ==> 1\n");
        printf("to add data in the end press        ==> 2\n");
        printf("to add data after the element press ==> 3\n");
        printf("to display the list press           ==> 4\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data that you wnat to enter in node: ");
            scanf("%d", &data);
            insertAtBegin(data);
            break;
        case 2:
            printf("Enter data that you wnat to enter in node: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 3:
            printf("Enter data that you wnat to enter in node: ");
            scanf("%d", &data);
             printf("Enter the position that you wnat to enter in node: ");
            scanf("%d", &position);
            insertAfterElement(position, data);
            break;
        case 4:
            printf("printing list\n");
            displayList();
            break;

        default:
            break;
        }
    }

    return 0;
}

void insertAtBegin(int data)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }

    else
    {
        temp->next = head;
        head = temp;
    }
}
void displayList()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("[ %d ] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    printf("\n");
}

void insertAtEnd(int data)
{
    struct Node *temp;
    struct Node *traverser = head;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        while (traverser->next != NULL)
        {
            traverser = traverser->next;
        }
        traverser->next = temp;
        tail = temp;
    }
}
void insertAfterElement(int position, int data)
{
    struct Node *traverser = head;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    if (traverser == NULL)
    {
        head = temp;
    }
    else
    {
        for (int i = 0; i < position && temp != NULL; i++)
        {
            traverser = traverser->next;
        }
        temp->next = traverser->next;
        traverser->next = temp;
    }
}