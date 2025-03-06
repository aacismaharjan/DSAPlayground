#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Queue structure
struct Queue {
    struct Node *front, *rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue an element
void enqueue(struct Queue *q, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode; // Second Last element should point to newNode (last element)
    q->rear = newNode;
}

// Function to dequeue an element
void dequeue(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) // If queue becomes empty
        q->rear = NULL;

    free(temp);
}

// Function to get the front element
int peek(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->data;
}

// Function to check if queue is empty
int isEmpty(struct Queue *q) {
    return q->front == NULL;
}

// Function to print the queue
void printQueue(struct Queue *q) {
    struct Node *temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Queue *q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    
    printQueue(q); // Output: 10 -> 20 -> 30 -> NULL

    printf("Front: %d\n", peek(q)); // Output: 10

    dequeue(q);
    printQueue(q); // Output: 20 -> 30 -> NULL

    dequeue(q);
    dequeue(q);
    dequeue(q); // Output: Queue is empty!

    printf("Queue Empty? %s\n", isEmpty(q) ? "Yes" : "No"); // Output: Yes

    free(q);
    return 0;
}

