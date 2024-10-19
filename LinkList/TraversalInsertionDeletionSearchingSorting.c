#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;           // Data part of the node
    struct Node* next;  // Pointer to the next node
};

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Set the data of the new node
    new_node->data = new_data;
    
    // Make the new node point to the current head
    new_node->next = (*head_ref);
    
    // Move the head to point to the new node
    (*head_ref) = new_node;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Set the data of the new node
    new_node->data = new_data;
    
    // Make the new node point to NULL (as it will be the last node)
    new_node->next = NULL;
    
    // If the list is empty, make the new node the head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    // Traverse to the last node
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    
    // Make the last node point to the new node
    last->next = new_node;
}

// Function to insert a node at a specific position in the linked list
void insertAtPosition(struct Node** head_ref, int new_data, int position) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Set the data of the new node
    new_node->data = new_data;
    
    // If the position is 0, insert at the beginning
    if (position == 0) {
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
        return;
    }
    
    // Traverse to the node just before the position
    struct Node* current = *head_ref;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    // If the position is out of bounds, do nothing
    if (current == NULL) {
        free(new_node);
        return;
    }
    
    // Insert the new node at the position
    new_node->next = current->next;
    current->next = new_node;
}

// Function to delete a node with a given value from the linked list
void deleteNode(struct Node** head_ref, int key) {
    // Store the head node
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    
    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Change head
        free(temp);             // Free old head
        return;
    }
    
    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    // If the key was not present in the linked list
    if (temp == NULL) return;
    
    // Unlink the node from the linked list
    prev->next = temp->next;
    
    // Free the memory of the deleted node
    free(temp);
}

// Function to search for a node with a given value in the linked list
int searchNode(struct Node* head, int key) {
    struct Node* current = head;
    
    // Traverse the list
    while (current != NULL) {
        if (current->data == key) {
            return 1; // Found
        }
        current = current->next;
    }
    
    return 0; // Not found
}

// Function to traverse and print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
void reverseList(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;        // Move the pointers one position ahead
        current = next;
    }
    
    *head_ref = prev;  // Update the head to the new first node
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;
    
    // Insert nodes
    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    insertAtPosition(&head, 4, 1);
    
    // Print the list
    printf("Linked list after insertion: ");
    printList(head);
    
    // Delete a node
    deleteNode(&head, 2);
    
    // Print the list after deletion
    printf("Linked list after deletion: ");
    printList(head);
    
    // Search for a node
    int key = 3;
    if (searchNode(head, key)) {
        printf("%d is found in the list.\n", key);
    } else {
        printf("%d is not found in the list.\n", key);
    }
    
    // Reverse the list
    reverseList(&head);
    
    // Print the reversed list
    printf("Linked list after reversal: ");
    printList(head);
    
    return 0;
}