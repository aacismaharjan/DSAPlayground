#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define maximum size of stack

// Structure to represent stack
struct Stack {
	int arr[MAX];
	int top;
};

// Function to initialize stack
void initStack(struct Stack *stack) {
	stack -> top = -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
	return stack -> top == MAX - 1;	
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
	return stack-> top == -1;
}

// Function to push an item onto the stack
void push(struct Stack *stack, int value) {
	if(isFull(stack)) {
		printf("Stack Overflow\n");
		return;
	}
	stack->arr[++stack->top] = value;
	printf("%d pushed onto stack\n", value);
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
	if(isEmpty(stack)) {
		printf("Stack Underflow\n");
		return -1; // Return -1 if the stack is empty
	}	
	return stack->arr[stack->top--];
}

// Function to get the top element of the stack
int peek(struct Stack *stack) {
	if(isEmpty(stack)) {
		printf("Stack is empty\n");
	}
	
	return stack->arr[stack->top];
}

int main() {
	struct Stack stack;
	initStack(&stack);
	
	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);
	
	printf("Top element is %d\n", peek(&stack));
	
	printf("%d popped from stack\n", pop(&stack));
	printf("%d popped from stack\n", pop(&stack));
	return 0;
}
