/*
 * LinkedList in C 
 * Practice Session
 */
 #include<stdio.h>
 #include<stdlib.h>


// Node Structure
struct Node {
	int data;
	struct Node *next;
};


// Function to insert a node at the beginning
void insertBeginning(struct Node **head, int value) {
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
	if(!newNode) {
		printf("Memory allocation failed.\n");
		return;
	}
	
	newNode->data=value;
	newNode->next=*head;
	*head = newNode;
}

// Function to insert a node at the end
void insertEnd(struct Node **head, int value) {
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
	
	if(!newNode) {
		printf("Memory allocation failed!\n");
		return;
	}
	
	newNode->data = value;
	newNode->next = NULL;
	
	if(*head == NULL) {
		*head = newNode;
		return;
	}
	
	struct Node *temp = *head;
	while(temp -> next != NULL) {
		temp = temp->next;
	}
	
	temp->next = newNode;
}


// Function to print the linked list
void printList(struct Node *node) {
    printf("Linked List: ");
    while (node != NULL) {
        printf("%d [%d] -> ", node->data, &node->next);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to delete a node by value
void deleteNode(struct Node **head, int value) {
	struct Node *temp = *head, *prev = NULL;
	
	// If head node itself is to be deleted
	if(temp != NULL && temp->data == value) {
		*head = temp -> next;
		free(temp);
		return;
	}
	
	// Find the node to be deleted
	while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    
    // If value not found
    if (temp == NULL) {
        printf("Value %d not found in the list!\n", value);
        return;
    }
    
    prev->next = temp->next;
    free(temp);
}

// Function to free the entire linked list
void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    struct Node *head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertBeginning(&head, 5);
    insertEnd(&head, 30);
    
    printList(head);

    deleteNode(&head, 20);
    printList(head);

    freeList(head);
    return 0;
}
