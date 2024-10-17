#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev; // Pointer to the previous node
    struct Node* next; // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front of the list
void insertFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;

    if (*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
}

// Function to print the list forward
void printList(struct Node* node) {
    struct Node* last;
    printf("Traversal in forward direction: \n");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nTraversal in reverse direction: \n");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
}

// Main function to test the doubly linked list
int main() {
    struct Node* head = NULL;

    // Insert nodes into the list
    insertFront(&head, 10);
    insertFront(&head, 20);
    insertFront(&head, 30);

    // Print the list
    printList(head);

    return 0;
}
