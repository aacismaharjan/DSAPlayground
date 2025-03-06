#include<stdio.h>
#include<stdlib.h>

struct Node {
	int key;
	struct Node *left, *right;
};

struct Node* createNode(int key) {
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->key = key;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// Function to insert a key in BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    
    return root;
}

// Function to search a key in BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    
    if (key < root->key) {
        return search(root->left, key);
    }
    
    return search(root->right, key);
}

// Function for in-order traversal (Left, Root, Right)
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Main function to test BST operations
int main() {
    struct Node* root = NULL;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};
    
    // Insert keys into BST
    for (int i = 0; i < 7; i++) {
        root = insert(root, keys[i]);
    }
    
    // In-order Traversal
    printf("In-order Traversal: ");
    inOrder(root);
    printf("\n");

    // Search for a key
    int searchKey = 40;
    struct Node* found = search(root, searchKey);
    if (found) {
        printf("Key %d found in BST.\n", searchKey);
    } else {
        printf("Key %d not found in BST.\n", searchKey);
    }

    return 0;
}
