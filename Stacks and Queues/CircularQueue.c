#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Define the maximum size of the queue

// Circular Queue structure
struct CircularQueue {
    int items[SIZE];
    int front;
    int rear;
};

// Initialize the queue by setting front and rear to -1
void initializeQueue(struct CircularQueue* cq) {
    cq->front = -1;
    cq->rear = -1;
}

// Check if the queue is full
int isFull(struct CircularQueue* cq) {
    return (cq->front == (cq->rear + 1) % SIZE);
}

// Check if the queue is empty
int isEmpty(struct CircularQueue* cq) {
    return (cq->front == -1);
}

// Enqueue operation to insert an element into the queue
void enqueue(struct CircularQueue* cq, int value) {
    if (isFull(cq)) {
        printf("Queue is full!\n");
    } else {
        // If inserting the first element, set front = 0
        if (cq->front == -1)
            cq->front = 0;
        
        // Update rear to the next position in a circular way
        cq->rear = (cq->rear + 1) % SIZE;
        cq->items[cq->rear] = value;
        printf("Inserted %d\n", value);
    }
}

// Dequeue operation to remove an element from the queue
int dequeue(struct CircularQueue* cq) {
    int element;
    if (isEmpty(cq)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        element = cq->items[cq->front];  // Get the front element
        
        // If the queue has only one element, reset to empty
        if (cq->front == cq->rear) {
            cq->front = -1;
            cq->rear = -1;
        } else {
            // Move front to the next position in a circular way
            cq->front = (cq->front + 1) % SIZE;
        }
        printf("Deleted %d\n", element);
        return element;
    }
}

// Function to display the queue
void display(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty!\n");
    } else {
        int i = cq->front;
        printf("Queue elements: ");
        while (i != cq->rear) {
            printf("%d ", cq->items[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d\n", cq->items[i]);  // Print the last element (rear)
    }
}

int main() {
    struct CircularQueue cq;
    initializeQueue(&cq);

    enqueue(&cq, 10);
    enqueue(&cq, 20);
    enqueue(&cq, 30);
    enqueue(&cq, 40);
    enqueue(&cq, 50);  // This will fill the queue
    
    display(&cq);  // Display the queue
    
    dequeue(&cq);  // Remove element
    dequeue(&cq);  // Remove element
    
    display(&cq);  // Display the queue after deletion
    
    enqueue(&cq, 60);  // Add new element
    display(&cq);  // Display the updated queue

    return 0;
}
