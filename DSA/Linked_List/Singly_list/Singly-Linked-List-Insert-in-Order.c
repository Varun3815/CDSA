#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head, *tail;

void insertAtBegin(int);
void insertInOrder(int);
void append(int);
void displayList();
int main()
{
    insertInOrder(1);
    insertInOrder(3);
    insertInOrder(2);
    insertInOrder(7);
    insertInOrder(4);
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
    printf("Null\n");
}

void append(int data)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (tail == NULL)
    {
        tail = temp;
        head = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void insertInOrder(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *traverser = head;
    struct Node *prev = NULL;

    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }

    while (traverser != NULL && traverser->data < data)
    {
        prev = traverser;
        traverser = traverser->next;
    }

    if (prev == NULL)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        temp->next = traverser;
        prev->next = temp;
    }
}
