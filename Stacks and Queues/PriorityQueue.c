#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Define the maximum size of the priority queue

// Structure to store elements and their priorities
struct PriorityQueue {
    int items[SIZE];
    int priorities[SIZE];
    int count;
};

// Initialize the priority queue
void initializeQueue(struct PriorityQueue* pq) {
    pq->count = 0;  // Set initial count to 0
}

// Check if the priority queue is full
int isFull(struct PriorityQueue* pq) {
    return pq->count == SIZE;
}

// Check if the priority queue is empty
int isEmpty(struct PriorityQueue* pq) {
    return pq->count == 0;
}

// Enqueue operation with priority
void enqueue(struct PriorityQueue* pq, int value, int priority) {
    if (isFull(pq)) {
        printf("Queue is full!\n");
        return;
    }

    int i;
    // Find the correct position based on priority
    for (i = pq->count - 1; i >= 0 && pq->priorities[i] < priority; i--) {
        pq->items[i + 1] = pq->items[i];
        pq->priorities[i + 1] = pq->priorities[i];
    }
    // Insert the element in its position
    pq->items[i + 1] = value;
    pq->priorities[i + 1] = priority;
    pq->count++;
    printf("Inserted %d with priority %d\n", value, priority);
}

// Dequeue operation (removes the highest priority element)
int dequeue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty!\n");
        return -1;
    }
    // Remove the element with the highest priority (first element)
    int value = pq->items[0];
    // Shift all remaining elements
    for (int i = 0; i < pq->count - 1; i++) {
        pq->items[i] = pq->items[i + 1];
        pq->priorities[i] = pq->priorities[i + 1];
    }
    pq->count--;
    printf("Deleted %d\n", value);
    return value;
}

// Function to display the queue
void display(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements with priorities: ");
        for (int i = 0; i < pq->count; i++) {
            printf("%d(p%d) ", pq->items[i], pq->priorities[i]);
        }
        printf("\n");
    }
}

int main() {
    struct PriorityQueue pq;
    initializeQueue(&pq);

    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);
    enqueue(&pq, 40, 0);
    
    display(&pq);  // Display the queue
    
    dequeue(&pq);  // Remove the highest priority element
    dequeue(&pq);  // Remove the next highest priority element
    
    display(&pq);  // Display the queue after deletion
    
    return 0;
}
