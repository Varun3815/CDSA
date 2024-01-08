#include <stdio.h>
#include <stdlib.h>

#define Capacity 100
int stack[Capacity];
int top = -1;

int isFull();
int isEmpty();
void push(int);
void pop();
void printStack();

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    printStack();
    pop();
    printStack();
    return 0;
}

int isFull()
{
    if (top == Capacity - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(int data)
{
    if (isFull())
    {
        printf("stack is overflowing");
        exit(0);
    }
    else
    {
        top++;
        stack[top] = data;
        printf("%d is now pushed to stack \n", data);
    }
}
void pop()
{
    if (isEmpty)
    {
        int ele = stack[top];
        top--;
        printf("%d has been deleted from stack\n", ele);
        
    }
    else
    {
        printf("stack is underFlow\n");
        printf("%d", top);
        exit(0);
    }
}
void printStack()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
}
