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
void countNodeInList();
int main()
{
    insertAtBegin(1);
    insertAtBegin(2);
    insertAtBegin(3);
    insertAtBegin(4);
    displayList();
    countNodeInList();
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
    struct Node* temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void countNodeInList()
{
    struct Node* temp;
    int count = 0;
    temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("total number of nodes are: %d \n", count);

}
