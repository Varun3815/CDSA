#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data);
void displayList(struct Node *);
struct Node *mergeTwoLists(struct Node *, struct Node *);
void insertAtEnd(struct Node **, int);

int main()
{
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    printf("first list\n");

    insertAtEnd(&head1, 1);
    insertAtEnd(&head1, 2);
    insertAtEnd(&head1, 3);
    displayList(head1);

    printf("second list\n");

    insertAtEnd(&head2, 5);
    insertAtEnd(&head2, 10);
    insertAtEnd(&head2, 15);
    displayList(head2);

    struct Node *mergelist = mergeTwoLists(head1, head2);
    printf("Merged List \n");
    displayList(mergelist);

    return 0;
}


struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("memory not allocated \n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void displayList(struct Node *headRef)
{
    struct Node *temp = headRef;
    while (temp != NULL)
    {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

struct Node *mergeTwoLists(struct Node *list1, struct Node *list2)
{
    struct Node *result = NULL;
    /* Base cases */
    if (list1 == NULL)
        return (list2);
    else if (list2 == NULL)
        return (list1);

    /* Pick either a or b, and recur */
    if (list1->data <= list2->data)
    {
        result = list1;
        result->next = mergeTwoLists(list1->next, list2);
    }
    else
    {
        result = list2;
        result->next = mergeTwoLists(list1, list2->next);
    }
    return result;
}

void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
