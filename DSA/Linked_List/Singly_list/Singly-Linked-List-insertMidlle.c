#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void insertAtBegin(int);
void displayList();

void insertAfter(int, int);

int main()
{
    insertAtBegin(1);
    insertAtBegin(2);
    insertAtBegin(3);
    insertAtBegin(4);
    displayList();
    insertAfter(2, 3);
    displayList();

    return 0;
}

void insertAtBegin(int data)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
        head = temp;

    else
    {
        temp->next = head;
        head = temp;
    }
}

void displayList()
{
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAfter(int position, int data)
{

    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node *temp = head;
    if (temp == NULL)
    {
        temp = newNode;
    }
    else
    {
        for (int i = 0; i < position && temp != NULL; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

//id name sem 

//display all the node on list 
//insert node at front
//insert at rear