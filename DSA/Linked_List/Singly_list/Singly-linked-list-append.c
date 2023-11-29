#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head, *tail;

void append(int data);
void displayList();
int main()
{
    append(1);
    append(2);
    append(3);
    append(4);
    displayList();
    return 0;
}
void append(int data)
{
    struct Node *temp;
    temp = (struct Node* )malloc(sizeof(struct Node));
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
void displayList()
{
    struct Node *temp;
    temp = head;
    while(temp != NULL)
    {
        printf("[ %d ] -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}