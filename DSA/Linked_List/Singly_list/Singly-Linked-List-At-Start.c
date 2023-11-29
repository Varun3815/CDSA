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
int main()
{
    insertAtBegin(1);
    insertAtBegin(2);
    insertAtBegin(3);
    insertAtBegin(4);
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
    struct Node* temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%d -> \n", temp->data);
        temp = temp->next;
    }

}
