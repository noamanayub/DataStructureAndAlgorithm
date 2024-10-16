#include <stdio.h> // Standard input-output library

// Define the structure for a node
struct Node {
    int data;            // Data stored in the node
    struct Node* next;   // Pointer to the next node
};

// Create an array of 5 nodes (fixed size)
struct Node nodes[5];

// Function to initialize the linked list with random data
void initializeList() {
    // Add random data to each node and manually link them
    nodes[0].data = 10;   // Set data for first node
    nodes[0].next = &nodes[1];  // Link first node to second node
    
    nodes[1].data = 20;   // Set data for second node
    nodes[1].next = &nodes[2];  // Link second node to third node
    
    nodes[2].data = 30;   // Set data for third node
    nodes[2].next = &nodes[3];  // Link third node to fourth node
    
    nodes[3].data = 40;   // Set data for fourth node
    nodes[3].next = &nodes[4];  // Link fourth node to fifth node
    
    nodes[4].data = 50;   // Set data for fifth node
    nodes[4].next = NULL; // Last node, so next is NULL (end of the list)
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;  // Temporary pointer to traverse the list
    
    // Traverse the list and print each node's data
    while (temp != NULL) {
        printf("%d -> ", temp->data);  // Print the data of the current node
        temp = temp->next;  // Move to the next node in the list
    }
    
    printf("NULL\n");  // Indicate the end of the list
}

int main() {
    initializeList();  // Initialize the list with 5 nodes and random data
    
    // Print the list starting from the first node
    printList(&nodes[0]);  // Head of the list is the first element of the array
    
    return 0;  // End of program
}
