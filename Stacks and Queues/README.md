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