### 4. Stacks

#### Definition and Properties
A stack is a linear data structure that follows the Last In, First Out (LIFO) principle. This means that the last element added to the stack will be the first one to be removed. The two primary operations that can be performed on a stack are:
- **Push**: Adds an element to the top of the stack.
- **Pop**: Removes the top element from the stack.
- **Peek (or Top)**: Returns the top element of the stack without removing it.

#### Operations
1. **Push**: Adds an element to the top of the stack.
2. **Pop**: Removes the top element from the stack.
3. **Peek (or Top)**: Returns the top element of the stack without removing it.

#### Applications
1. **Expression Evaluation**: Stacks are used to evaluate expressions in languages like postfix, prefix, and infix.
2. **Backtracking**: Stacks are used in algorithms like depth-first search (DFS) for backtracking.
3. **Function Calls**: Stacks are used to manage function calls in programming languages, where each function call is pushed onto the stack, and when the function returns, it is popped off the stack.

### Implementation in C

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1; // Assuming -1 as an error code
    }
    return s->data[s->top--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is Empty\n");
        return -1; // Assuming -1 as an error code
    }
    return s->data[s->top];
}

int main() {
    Stack s;
    initialize(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", peek(&s));

    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));

    printf("Top element: %d\n", peek(&s));

    return 0;
}
```

### Explanation of the C Code
1. **Stack Structure**: The stack is defined as a structure with an array `data` to hold the elements and an integer `top` to keep track of the top of the stack.
2. **Initialize**: The `initialize` function sets the `top` to `-1` to indicate an empty stack.
3. **isEmpty and isFull**: These functions check if the stack is empty or full, respectively.
4. **Push**: The `push` function adds an element to the top of the stack if it is not full.
5. **Pop**: The `pop` function removes and returns the top element of the stack if it is not empty.
6. **Peek**: The `peek` function returns the top element of the stack without removing it.

### Implementation in Python

```python
class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if self.is_empty():
            print("Stack Underflow")
            return None
        return self.items.pop()

    def peek(self):
        if self.is_empty():
            print("Stack is Empty")
            return None
        return self.items[-1]

# Example usage
stack = Stack()
stack.push(10)
stack.push(20)
stack.push(30)

print("Top element:", stack.peek())

print("Popped element:", stack.pop())
print("Popped element:", stack.pop())

print("Top element:", stack.peek())
```

### Explanation of the Python Code
1. **Stack Class**: The stack is implemented as a class with a list `items` to hold the elements.
2. **is_empty**: This method checks if the stack is empty.
3. **push**: The `push` method adds an element to the end of the list.
4. **pop**: The `pop` method removes and returns the last element of the list if the stack is not empty.
5. **peek**: The `peek` method returns the last element of the list without removing it.

### Implementation in Java

```java
import java.util.ArrayList;

class Stack {
    private ArrayList<Integer> items;

    public Stack() {
        items = new ArrayList<>();
    }

    public boolean isEmpty() {
        return items.isEmpty();
    }

    public void push(int item) {
        items.add(item);
    }

    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack Underflow");
            return -1; // Assuming -1 as an error code
        }
        return items.remove(items.size() - 1);
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is Empty");
            return -1; // Assuming -1 as an error code
        }
        return items.get(items.size() - 1);
    }

    public static void main(String[] args) {
        Stack stack = new Stack();
        stack.push(10);
        stack.push(20);
        stack.push(30);

        System.out.println("Top element: " + stack.peek());

        System.out.println("Popped element: " + stack.pop());
        System.out.println("Popped element: " + stack.pop());

        System.out.println("Top element: " + stack.peek());
    }
}
```

### Explanation of the Java Code
1. **Stack Class**: The stack is implemented as a class with an `ArrayList` `items` to hold the elements.
2. **isEmpty**: This method checks if the stack is empty.
3. **push**: The `push` method adds an element to the end of the list.
4. **pop**: The `pop` method removes and returns the last element of the list if the stack is not empty.
5. **peek**: The `peek` method returns the last element of the list without removing it.

### Summary
- **C**: Uses an array to implement the stack, with manual management of the `top` index.
- **Python**: Uses a list, which provides built-in methods for `append` (push) and `pop`.
- **Java**: Uses an `ArrayList`, which provides similar methods to Python's list.

Each implementation follows the LIFO principle and supports the basic operations of a stack: push, pop, and peek. The choice of language may depend on the specific requirements and constraints of the project.

<hr>
<hr>
<hr>

### 5. Queues

#### Definition and Properties
A queue is a linear data structure that follows the First In, First Out (FIFO) principle. This means that the first element added to the queue will be the first one to be removed. The two primary operations that can be performed on a queue are:
- **Enqueue**: Adds an element to the end of the queue.
- **Dequeue**: Removes the front element from the queue.
- **Peek (or Front)**: Returns the front element of the queue without removing it.

#### Types of Queues
1. **Simple Queue**: A basic queue with operations limited to enqueue and dequeue.
2. **Circular Queue**: A queue where the last position is connected back to the first position to make a circle.
3. **Priority Queue**: A queue where each element has a priority, and elements are dequeued based on their priority.
4. **Double-ended Queue (Deque)**: A queue where elements can be added or removed from both ends.

#### Operations
1. **Enqueue**: Adds an element to the end of the queue.
2. **Dequeue**: Removes the front element from the queue.
3. **Peek (or Front)**: Returns the front element of the queue without removing it.

#### Applications
1. **Task Scheduling**: Queues are used in operating systems to manage tasks or processes.
2. **Buffer Management**: Queues are used in buffering data streams, such as in networking or multimedia applications.

### Simple Queue Implementation in C

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->data[++q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1; // Assuming -1 as an error code
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1; // Assuming -1 as an error code
    }
    return q->data[q->front];
}

int main() {
    Queue q;
    initialize(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Front element: %d\n", peek(&q));

    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));

    printf("Front element: %d\n", peek(&q));

    return 0;
}
```

### Circular Queue Implementation in C

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} CircularQueue;

void initialize(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(CircularQueue *q) {
    return q->front == -1;
}

int isFull(CircularQueue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1; // Assuming -1 as an error code
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return value;
}

int peek(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1; // Assuming -1 as an error code
    }
    return q->data[q->front];
}

int main() {
    CircularQueue q;
    initialize(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Front element: %d\n", peek(&q));

    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));

    printf("Front element: %d\n", peek(&q));

    return 0;
}
```

### Priority Queue Implementation in Python

```python
import heapq

class PriorityQueue:
    def __init__(self):
        self.elements = []

    def is_empty(self):
        return len(self.elements) == 0

    def enqueue(self, item, priority):
        heapq.heappush(self.elements, (priority, item))

    def dequeue(self):
        if self.is_empty():
            print("Queue Underflow")
            return None
        return heapq.heappop(self.elements)[1]

    def peek(self):
        if self.is_empty():
            print("Queue is Empty")
            return None
        return self.elements[0][1]

# Example usage
pq = PriorityQueue()
pq.enqueue("Task 1", 3)
pq.enqueue("Task 2", 1)
pq.enqueue("Task 3", 2)

print("Front element:", pq.peek())

print("Dequeued element:", pq.dequeue())
print("Dequeued element:", pq.dequeue())

print("Front element:", pq.peek())
```

### Double-ended Queue (Deque) Implementation in Java

```java
import java.util.ArrayDeque;

class Deque {
    private ArrayDeque<Integer> deque;

    public Deque() {
        deque = new ArrayDeque<>();
    }

    public boolean isEmpty() {
        return deque.isEmpty();
    }

    public void enqueueFront(int item) {
        deque.addFirst(item);
    }

    public void enqueueRear(int item) {
        deque.addLast(item);
    }

    public int dequeueFront() {
        if (isEmpty()) {
            System.out.println("Deque Underflow");
            return -1; // Assuming -1 as an error code
        }
        return deque.removeFirst();
    }

    public int dequeueRear() {
        if (isEmpty()) {
            System.out.println("Deque Underflow");
            return -1; // Assuming -1 as an error code
        }
        return deque.removeLast();
    }

    public int peekFront() {
        if (isEmpty()) {
            System.out.println("Deque is Empty");
            return -1; // Assuming -1 as an error code
        }
        return deque.getFirst();
    }

    public int peekRear() {
        if (isEmpty()) {
            System.out.println("Deque is Empty");
            return -1; // Assuming -1 as an error code
        }
        return deque.getLast();
    }

    public static void main(String[] args) {
        Deque deque = new Deque();
        deque.enqueueFront(10);
        deque.enqueueRear(20);
        deque.enqueueFront(5);

        System.out.println("Front element: " + deque.peekFront());
        System.out.println("Rear element: " + deque.peekRear());

        System.out.println("Dequeued front element: " + deque.dequeueFront());
        System.out.println("Dequeued rear element: " + deque.dequeueRear());

        System.out.println("Front element: " + deque.peekFront());
        System.out.println("Rear element: " + deque.peekRear());
    }
}
```

### Summary
- **Simple Queue**: A basic queue with operations limited to enqueue and dequeue.
- **Circular Queue**: A queue where the last position is connected back to the first position to make a circle.
- **Priority Queue**: A queue where each element has a priority, and elements are dequeued based on their priority.
- **Double-ended Queue (Deque)**: A queue where elements can be added or removed from both ends.

Each implementation follows the FIFO principle and supports the basic operations of a queue: enqueue, dequeue, and peek. The choice of language and type of queue may depend on the specific requirements and constraints of the project.