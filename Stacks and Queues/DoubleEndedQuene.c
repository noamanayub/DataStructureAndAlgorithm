#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the deque

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

// Initialize deque
void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = 0;
    dq->size = 0;
}

// Check if deque is full
int isFull(Deque *dq) {
    return dq->size == MAX;
}

// Check if deque is empty
int isEmpty(Deque *dq) {
    return dq->size == 0;
}

// Insert element at the rear
void insertRear(Deque *dq, int key) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    dq->rear = (dq->rear + 1) % MAX;
    dq->arr[dq->rear] = key;
    dq->size++;
}

// Insert element at the front
void insertFront(Deque *dq, int key) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    dq->front = (dq->front - 1 + MAX) % MAX;
    dq->arr[dq->front] = key;
    dq->size++;
}

// Delete element from the front
void deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    dq->front = (dq->front + 1) % MAX;
    dq->size--;
}

// Delete element from the rear
void deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    dq->rear = (dq->rear - 1 + MAX) % MAX;
    dq->size--;
}

// Get the front element
int getFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->arr[dq->front];
}

// Get the rear element
int getRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->arr[dq->rear];
}

int main() {
    Deque dq;
    initDeque(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 30);
    insertFront(&dq, 40);

    printf("Front element: %d\n", getFront(&dq));  // Should be 40
    printf("Rear element: %d\n", getRear(&dq));    // Should be 20

    deleteFront(&dq);
    deleteRear(&dq);

    printf("After deletions:\n");
    printf("Front element: %d\n", getFront(&dq));  // Should be 30
    printf("Rear element: %d\n", getRear(&dq));    // Should be 10

    return 0;
}
