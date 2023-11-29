#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct Node
{
    int id;
    int sem;
    char name[30];
    struct Node *next;
};

struct Node *head;

void insertAtBegin(int id, int sem, char name[30])
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->id = id;
    temp->sem = sem;
    strcpy(temp->name, name);
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
        printf("[ %d| %d| %s| ] -> ", temp->id, temp->sem, temp->name);
        temp = temp->next;
    }
    printf("NULL");
}
int main()
{
    insertAtBegin(1, 1, "varun");
    insertAtBegin(2, 1, "parth");
    insertAtBegin(3, 1, "sumukha");
    insertAtBegin(4, 1, "raghav");
    insertAtBegin(5, 1, "lovesh");
    displayList();
    return 0;
}


