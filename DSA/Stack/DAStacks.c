#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 5

struct Stack {
    int *array;
    int top;
    int capacity;
};

struct Stack *initializeStack() {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    if (!stack) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    stack->array = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    if (!stack->array) {
        perror("Memory allocation failed");
        free(stack);
        exit(EXIT_FAILURE);
    }

    stack->top = -1;
    stack->capacity = INITIAL_CAPACITY;
    return stack;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void resize(struct Stack *stack) {
    stack->capacity *= 2;
    stack->array = (int *)realloc(stack->array, stack->capacity * sizeof(int));
    if (!stack->array) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
}

void push(struct Stack *stack, int element) {
    if (stack->top == stack->capacity - 1) {
        resize(stack);
    }
    stack->array[++stack->top] = element;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack underflow: Cannot pop from an empty stack\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top--];
}

int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack is empty: Cannot peek\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top];
}

void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

void freeStack(struct Stack *stack) {
    free(stack->array);
    free(stack);
}

int main() {
    struct Stack *stack = initializeStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    display(stack);

    printf("Peek: %d\n", peek(stack));

    pop(stack);
    display(stack);

    freeStack(stack);

    return 0;
}
