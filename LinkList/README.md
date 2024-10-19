There are three main types of linked lists: 

1. **Singly Linked List**  
2. **Doubly Linked List**  
3. **Circular Linked List**  

Let’s break down each one in simple terms:

---

### 1. **Singly Linked List**:
- **Structure**: In a singly linked list, each node contains two things: the data (value) and a reference (or link) to the next node in the list. 
- **One-Way Direction**: It’s like a chain of people where each person holds the hand of the next person in line, but there’s no way to go backward.
- **Example**: If you have nodes A → B → C → D, A knows where B is, B knows where C is, and so on, but you can’t go back from B to A.
- **Usage**: Singly linked lists are used in simple data structures like stacks, where you only need to access one side (like the top of the stack).

---

### 2. **Doubly Linked List**:
- **Structure**: In a doubly linked list, each node has three things: the data, a link to the next node, and a link to the previous node.
- **Two-Way Direction**: It’s like a train where each coach is connected to the next one and also to the previous one, allowing you to move both forward and backward.
- **Example**: If you have nodes A ↔ B ↔ C ↔ D, A knows where B is, B knows where A and C are, and so on. This way, you can move forward and backward through the list.
- **Usage**: Doubly linked lists are used in places where you need to traverse data in both directions, such as in browsers where you move forward and back between web pages.

---

### 3. **Circular Linked List**:
- **Structure**: Circular linked lists can be either singly or doubly linked, but what makes them different is that the last node points back to the first node, forming a circle.
- **Continuous Loop**: It’s like a group of people holding hands in a circle where there’s no definite start or end. You can keep moving around without reaching an "end."
- **Example**: In a singly circular linked list, if you have nodes A → B → C → D, the last node D points back to A instead of `null`, creating a loop. The same can happen in a doubly circular linked list.
- **Usage**: Circular linked lists are used in situations where you need continuous cycling through data, like in round-robin scheduling in operating systems or circular queues.


Here are simple **Singly Linked List** implementations in **C**, **Java**, and **Python** with detailed comments explaining pointer referencing, memory management, and syntax:

---

### 1. **C Code (Singly Linked List)**

```c
#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in the linked list
struct Node {
    int data;              // Holds the value (data) of the node
    struct Node* next;     // Pointer to the next node (link to next)
};

// Function to create a new node
struct Node* createNode(int data) {
    // Dynamically allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = data;  // Set the data for the node
    newNode->next = NULL;  // Initially, the next pointer is set to NULL

    return newNode;  // Return the pointer to the newly created node
}

// Function to print the entire linked list
void printList(struct Node* head) {
    struct Node* current = head;  // Start from the head of the list

    while (current != NULL) {     // Traverse until you reach the end (NULL)
        printf("%d -> ", current->data);  // Print the current node's data
        current = current->next;          // Move to the next node
    }
    printf("NULL\n");  // End of the list
}

int main() {
    // Create the first node (head)
    struct Node* head = createNode(10);
    
    // Add more nodes
    head->next = createNode(20);  // Create second node and link it to head
    head->next->next = createNode(30);  // Create third node and link to second

    // Print the list
    printList(head);

    return 0;
}
```

#### Explanation:
- **Node Structure**: Each node has two parts: an integer `data` and a pointer `next` to the next node.
- **Memory Allocation (`malloc`)**: We dynamically allocate memory for each node using `malloc`. This ensures that new nodes can be created at runtime.
- **Pointer Referencing**: `head` points to the first node, `head->next` points to the second node, and so on. This is how we traverse the list using pointers.

---

### 2. **Java Code (Singly Linked List)**

```java
class Node {
    int data;     // Holds the data of the node
    Node next;    // Holds the reference (pointer) to the next node

    // Constructor to create a new node
    Node(int data) {
        this.data = data;
        this.next = null;  // By default, the next node is set to null
    }
}

public class LinkedList {
    Node head;  // Points to the head (first node) of the linked list

    // Method to add a new node to the end of the list
    public void append(int data) {
        if (head == null) {
            // If list is empty, create the first node
            head = new Node(data);
            return;
        }

        Node current = head;  // Start from the head of the list
        // Traverse to the last node
        while (current.next != null) {
            current = current.next;
        }
        current.next = new Node(data);  // Link the new node at the end
    }

    // Method to print the entire linked list
    public void printList() {
        Node current = head;  // Start from the head

        while (current != null) {  // Traverse the list
            System.out.print(current.data + " -> ");
            current = current.next;  // Move to the next node
        }
        System.out.println("NULL");
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        // Append nodes to the linked list
        list.append(10);
        list.append(20);
        list.append(30);

        // Print the list
        list.printList();
    }
}
```

#### Explanation:
- **Node Class**: Each node in Java has two fields: `data` for the value and `next` to point to the next node.
- **Constructor**: When creating a new node, the `next` pointer is initially `null`.
- **Linked List Class**: The `append` method traverses the list to find the last node and attaches the new node at the end.
- **References**: Java handles memory through object references. `head` holds the reference to the first node, and each node holds a reference to the next node.

---

### 3. **Python Code (Singly Linked List)**

```python
# Node class to represent a node in the linked list
class Node:
    def __init__(self, data):
        self.data = data  # Holds the data (value)
        self.next = None  # Holds reference to the next node (initially None)

# Linked List class to manage the list
class LinkedList:
    def __init__(self):
        self.head = None  # The head points to the first node (initially None)

    # Method to append a new node to the end of the list
    def append(self, data):
        new_node = Node(data)  # Create a new node with the given data

        if not self.head:  # If the list is empty, make this node the head
            self.head = new_node
            return

        current = self.head  # Start at the head of the list
        while current.next:  # Traverse the list to find the last node
            current = current.next

        current.next = new_node  # Link the new node at the end

    # Method to print the entire linked list
    def print_list(self):
        current = self.head  # Start at the head of the list

        while current:  # Traverse the list
            print(current.data, end=" -> ")
            current = current.next  # Move to the next node

        print("None")  # End of the list

# Example usage
if __name__ == "__main__":
    list = LinkedList()
    
    # Append nodes to the linked list
    list.append(10)
    list.append(20)
    list.append(30)

    # Print the linked list
    list.print_list()
```

#### Explanation:
- **Node Class**: Like in the other languages, the `Node` class has `data` for the value and `next` for the link to the next node.
- **LinkedList Class**: The `append` method adds a new node at the end of the list by traversing through all nodes.
- **Memory Management**: Python automatically handles memory allocation. When you create a `Node`, Python assigns memory, and garbage collection takes care of freeing memory when nodes are no longer used.
- **Pointers in Python**: Python doesn’t have explicit pointers like C, but `self.head` holds the reference to the first node, and each node holds the reference to the next one, acting like a pointer.

---

### Backend Functioning in All Languages:
1. **Node Creation**: A new node is created in memory, holding both data and the reference (or pointer) to the next node.
2. **Pointer Referencing**: Each node’s `next` field holds a reference to the memory location of the next node in the list. This allows us to chain nodes together.
3. **Traversal**: To traverse the list, we follow the `next` pointers, starting from the head node until we reach a `NULL` (or `None` in Python), indicating the end of the list.

<hr>
<hr>
<hr>

Here are the implementations of a doubly linked list (DLL) in C, Python, and Java, with detailed explanations and comments in the code.

---

### **C Implementation of a Doubly Linked List**
```c
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
```

#### **Explanation (C)**
- **Node Structure**: Each node has an integer data field, a `prev` pointer pointing to the previous node, and a `next` pointer pointing to the next node.
- **Insert Front**: We insert a new node at the front of the list, update pointers to maintain DLL properties.
- **Traversal**: The list is printed in both forward and reverse directions to demonstrate how the doubly linked pointers work.

### **What is `malloc` in C?**

`malloc` stands for **memory allocation** and is a function in the C standard library (specifically in `stdlib.h`) that dynamically allocates memory during runtime. Unlike static or stack memory allocation (where memory is allocated at compile time or automatically at function call), dynamic memory allocation allows a program to request memory as needed while it's running.

Here’s what `malloc` does:

- **Allocates a block of memory on the heap**: `malloc` allocates a specified number of bytes from the heap (a region of memory for dynamic allocation), which persists until explicitly deallocated.
- **Returns a pointer to the allocated memory**: If successful, `malloc` returns a pointer to the beginning of the allocated block of memory. The pointer is of type `void*`, which means it can be cast to any pointer type (like `int*`, `char*`, etc.).
- **Initializes memory to garbage**: The memory allocated by `malloc` is not initialized, so it contains whatever values were previously stored in that memory location (referred to as "garbage values").

### **Syntax of `malloc`**

```c
void* malloc(size_t size);
```

- **`size_t size`**: This argument specifies the number of bytes to allocate. You typically use `sizeof(type)` to calculate the size required for the data type.
- **Returns**: On success, it returns a pointer to the allocated memory. On failure (e.g., if there’s not enough memory available), it returns `NULL`.

### **Example of `malloc` in C**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for an integer
    int *ptr = (int*) malloc(sizeof(int));

    // Check if the memory allocation was successful
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit if memory allocation failed
    }

    // Store a value in the allocated memory
    *ptr = 42;
    printf("Value at ptr: %d\n", *ptr);

    // Free the allocated memory when no longer needed
    free(ptr);

    return 0;
}
```

### **Explanation**
1. **`int *ptr = (int*) malloc(sizeof(int));`**:
   - This line allocates enough memory for an integer (`sizeof(int)` usually returns 4 bytes).
   - The result of `malloc` is cast to `(int*)` to assign the correct type to the pointer.
   - If successful, `ptr` will now point to the newly allocated memory block where we can store an integer.
   
2. **Error Handling (`if (ptr == NULL)`)**:
   - It's important to check whether `malloc` returns `NULL`, which indicates a memory allocation failure (e.g., insufficient memory).
   
3. **Storing a Value (`*ptr = 42;`)**:
   - The allocated memory is used to store the integer value `42` by dereferencing the pointer (`*ptr`).

4. **Freeing Memory (`free(ptr);`)**:
   - Dynamically allocated memory using `malloc` does **not** get freed automatically. You must call `free(ptr)` when you are done using the memory, to avoid memory leaks.

### **Why Use `malloc`?**
- **Dynamic Memory Allocation**: When the size of an array or data structure cannot be determined at compile time (e.g., user input determines the size), `malloc` allows you to allocate memory on the fly during program execution.
- **Heap vs. Stack**: Variables allocated on the heap persist until they are explicitly freed, while variables on the stack (local variables) are automatically freed when they go out of scope (e.g., when a function ends).

### **Common Mistakes with `malloc`**
- **Not Checking for `NULL`**: Always check if `malloc` returns `NULL` to handle cases where memory allocation fails.
- **Memory Leaks**: Forgetting to `free` memory after use causes memory leaks, where allocated memory isn't reclaimed, leading to inefficient memory usage.
- **Dangling Pointers**: After freeing memory, the pointer should be set to `NULL` to avoid accessing freed memory.

---

In summary, `malloc` is a powerful tool in C for dynamically managing memory at runtime, but with great power comes the responsibility of manually managing memory and avoiding common pitfalls like leaks and invalid access.

---

### **Python Implementation of a Doubly Linked List**
```python
# Node class for doubly linked list
class Node:
    def __init__(self, data):
        self.data = data  # Initialize data
        self.prev = None  # Pointer to previous node
        self.next = None  # Pointer to next node

# Doubly linked list class
class DoublyLinkedList:
    def __init__(self):
        self.head = None  # Initialize head of the list

    # Function to insert a node at the front of the list
    def insert_front(self, data):
        new_node = Node(data)  # Create a new node
        new_node.next = self.head  # Make new node point to head

        if self.head is not None:
            self.head.prev = new_node  # Update previous head's prev pointer

        self.head = new_node  # Update head to new node

    # Function to print list in forward direction
    def print_list(self):
        current = self.head
        print("Traversal in forward direction:")
        while current:
            print(current.data, end=' ')
            last = current  # Save the last node to traverse backwards
            current = current.next

        print("\nTraversal in reverse direction:")
        while last:
            print(last.data, end=' ')
            last = last.prev

# Test the doubly linked list
dll = DoublyLinkedList()
dll.insert_front(10)
dll.insert_front(20)
dll.insert_front(30)

dll.print_list()
```

#### **Explanation (Python)**
- **Node Class**: Defines a `Node` with a data field, `prev` pointer, and `next` pointer.
- **DoublyLinkedList Class**: Manages the operations for inserting nodes at the front and printing the list.
- **Traversal**: As in the C version, the list is printed both forward and backward to illustrate the DLL structure.

---

### **Java Implementation of a Doubly Linked List**
```java
// Node class for doubly linked list
class Node {
    int data;
    Node prev; // Pointer to previous node
    Node next; // Pointer to next node

    // Constructor to create a new node
    public Node(int data) {
        this.data = data;
        this.prev = null;
        this.next = null;
    }
}

// Doubly linked list class
class DoublyLinkedList {
    Node head; // Head of the list

    // Constructor to initialize an empty list
    public DoublyLinkedList() {
        this.head = null;
    }

    // Function to insert a node at the front
    public void insertFront(int data) {
        Node newNode = new Node(data);
        newNode.next = head;

        if (head != null)
            head.prev = newNode;

        head = newNode;
    }

    // Function to print the list in forward direction
    public void printList() {
        Node current = head;
        Node last = null;
        System.out.println("Traversal in forward direction:");
        while (current != null) {
            System.out.print(current.data + " ");
            last = current; // Track last node for reverse printing
            current = current.next;
        }

        System.out.println("\nTraversal in reverse direction:");
        while (last != null) {
            System.out.print(last.data + " ");
            last = last.prev;
        }
    }

    // Main function to test the doubly linked list
    public static void main(String[] args) {
        DoublyLinkedList dll = new DoublyLinkedList();

        // Insert nodes at the front
        dll.insertFront(10);
        dll.insertFront(20);
        dll.insertFront(30);

        // Print the doubly linked list
        dll.printList();
    }
}
```

#### **Explanation (Java)**
- **Node Class**: Contains `data`, `prev`, and `next` pointers to store node information and maintain doubly linked structure.
- **DoublyLinkedList Class**: Handles insertion and printing functions.
- **Traversal**: List is printed forward and backward using the doubly linked pointers.

---

### **Key Points Across All Implementations**
1. **Node Creation**: Each node contains three components: `data`, a pointer to the `prev` node, and a pointer to the `next` node.
2. **Insertion at Front**: For inserting a node at the front, pointers are adjusted to maintain the doubly linked structure.
3. **Traversal**: The DLL is traversed in both forward and reverse directions to show the bidirectional nature of the structure.
4. **Memory Management**: In C, memory is manually managed using `malloc` and `free`, while Python and Java handle memory automatically.

<hr>
<hr>
<hr>

A circular linked list is a variation of a singly linked list where the last node points back to the first node instead of pointing to `null`. This creates a circular structure, allowing traversal to continue indefinitely or until a specific condition is met. Circular linked lists can be either singly or doubly linked.

### Key Characteristics:
1. **Circular Traversal**: You can traverse the list indefinitely by following the next pointers.
2. **Efficient Insertion/Deletion**: Inserting or deleting nodes at the beginning or end of the list is efficient.
3. **Applications**: Used in scenarios where you need to cycle through elements repeatedly, such as in round-robin scheduling, circular buffers, etc.

### Example: Singly Circular Linked List

#### Java
```java
class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class CircularLinkedList {
    Node head;

    CircularLinkedList() {
        head = null;
    }

    void insert(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            newNode.next = head;
        } else {
            Node temp = head;
            while (temp.next != head) {
                temp = temp.next;
            }
            temp.next = newNode;
            newNode.next = head;
        }
    }

    void display() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        Node temp = head;
        do {
            System.out.print(temp.data + " ");
            temp = temp.next;
        } while (temp != head);
        System.out.println();
    }

    public static void main(String[] args) {
        CircularLinkedList list = new CircularLinkedList();
        list.insert(1);
        list.insert(2);
        list.insert(3);
        list.display();
    }
}
```

#### Python
```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class CircularLinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            new_node.next = self.head
        else:
            temp = self.head
            while temp.next != self.head:
                temp = temp.next
            temp.next = new_node
            new_node.next = self.head

    def display(self):
        if not self.head:
            print("List is empty")
            return
        temp = self.head
        while True:
            print(temp.data, end=" ")
            temp = temp.next
            if temp == self.head:
                break
        print()

if __name__ == "__main__":
    cll = CircularLinkedList()
    cll.insert(1)
    cll.insert(2)
    cll.insert(3)
    cll.display()
```

#### C
```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CircularLinkedList {
    struct Node* head;
};

void insert(struct CircularLinkedList* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = list->head;
    } else {
        struct Node* temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = list->head;
    }
}

void display(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = list->head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("\n");
}

int main() {
    struct CircularLinkedList list = {NULL};
    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    display(&list);
    return 0;
}
```

### Explanation:
1. **Node Structure**: Each node contains data and a pointer to the next node.
2. **Circular Linked List Structure**: The list contains a reference to the head node.
3. **Insertion**: When inserting a new node, if the list is empty, the new node becomes the head and points to itself. Otherwise, traverse to the last node and make it point to the new node, which in turn points to the head.
4. **Display**: Traverse the list starting from the head and continue until you reach the head again, printing the data of each node.

### Output:
For all the above implementations, the output will be:
```
1 2 3 
```

This demonstrates the circular nature of the linked list, where the last node points back to the first node.

<hr>
<hr>
<hr>

Certainly! Below is a detailed implementation of a singly linked list in C, covering insertion, deletion, searching, traversal, and reversal. I'll explain each part of the code in detail.

### 1. **Node Structure**
First, we need to define the structure of a node in the linked list.

```c
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;           // Data part of the node
    struct Node* next;  // Pointer to the next node
};
```

### 2. **Insertion**
We will implement three types of insertion:
- **At the beginning**
- **At the end**
- **At a specific position**

#### **Insertion at the Beginning**
```c
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
```

#### **Insertion at the End**
```c
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
```

#### **Insertion at a Specific Position**
```c
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
```

### 3. **Deletion**
We will implement deletion by value.

```c
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
```

### 4. **Searching**
We will implement a function to search for a value in the linked list.

```c
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
```

### 5. **Traversal**
We will implement a function to traverse and print the linked list.

```c
// Function to traverse and print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
```

### 6. **Reversal**
We will implement a function to reverse the linked list.

```c
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
```

### 7. **Main Function**
Finally, we will write a `main` function to test all the operations.

```c
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
```

### **Explanation of Commands:**

1. **`malloc(sizeof(struct Node))`**: Allocates memory for a new node.
2. **`new_node->data = new_data`**: Sets the data of the new node.
3. **`new_node->next = (*head_ref)`**: Makes the new node point to the current head.
4. **`(*head_ref) = new_node`**: Updates the head to point to the new node.
5. **`while (last->next != NULL)`**: Traverses the list until the last node.
6. **`last->next = new_node`**: Links the last node to the new node.
7. **`free(temp)`**: Frees the memory of the deleted node.
8. **`printf("%d -> ", node->data)`**: Prints the data of the current node.
9. **`reverseList(&head)`**: Reverses the linked list.

### **Output:**
When you run the `main` function, the output will be:

```
Linked list after insertion: 2 -> 4 -> 1 -> 3 -> NULL
Linked list after deletion: 4 -> 1 -> 3 -> NULL
3 is found in the list.
Linked list after reversal: 3 -> 1 -> 4 -> NULL
```

This code covers all the basic operations on a linked list in C.

<hr>
<hr>
<hr>

Below are the complete implementations of a singly linked list in C, Python, and Java, covering insertion, deletion, searching, traversal, and reversal.

### **C Language Implementation**

```c
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
```

### **Python Implementation**

```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert_at_beginning(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node

    def insert_at_end(self, new_data):
        new_node = Node(new_data)
        if self.head is None:
            self.head = new_node
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = new_node

    def insert_at_position(self, new_data, position):
        if position == 0:
            self.insert_at_beginning(new_data)
            return
        new_node = Node(new_data)
        current = self.head
        for _ in range(position - 1):
            if current is None:
                return
            current = current.next
        if current is None:
            return
        new_node.next = current.next
        current.next = new_node

    def delete_node(self, key):
        temp = self.head
        if temp is not None and temp.data == key:
            self.head = temp.next
            temp = None
            return
        prev = None
        while temp is not None and temp.data != key:
            prev = temp
            temp = temp.next
        if temp is None:
            return
        prev.next = temp.next
        temp = None

    def search_node(self, key):
        current = self.head
        while current:
            if current.data == key:
                return True
            current = current.next
        return False

    def print_list(self):
        temp = self.head
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("None")

    def reverse_list(self):
        prev = None
        current = self.head
        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        self.head = prev

# Test the linked list
if __name__ == "__main__":
    llist = LinkedList()
    llist.insert_at_end(1)
    llist.insert_at_beginning(2)
    llist.insert_at_end(3)
    llist.insert_at_position(4, 1)

    print("Linked list after insertion:")
    llist.print_list()

    llist.delete_node(2)
    print("Linked list after deletion:")
    llist.print_list()

    key = 3
    if llist.search_node(key):
        print(f"{key} is found in the list.")
    else:
        print(f"{key} is not found in the list.")

    llist.reverse_list()
    print("Linked list after reversal:")
    llist.print_list()
```

### **Java Implementation**

```java
class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node head;

    void insertAtBeginning(int new_data) {
        Node new_node = new Node(new_data);
        new_node.next = head;
        head = new_node;
    }

    void insertAtEnd(int new_data) {
        Node new_node = new Node(new_data);
        if (head == null) {
            head = new_node;
            return;
        }
        Node last = head;
        while (last.next != null) {
            last = last.next;
        }
        last.next = new_node;
    }

    void insertAtPosition(int new_data, int position) {
        if (position == 0) {
            insertAtBeginning(new_data);
            return;
        }
        Node new_node = new Node(new_data);
        Node current = head;
        for (int i = 0; i < position - 1 && current != null; i++) {
            current = current.next;
        }
        if (current == null) {
            return;
        }
        new_node.next = current.next;
        current.next = new_node;
    }

    void deleteNode(int key) {
        Node temp = head, prev = null;
        if (temp != null && temp.data == key) {
            head = temp.next;
            return;
        }
        while (temp != null && temp.data != key) {
            prev = temp;
            temp = temp.next;
        }
        if (temp == null) {
            return;
        }
        prev.next = temp.next;
    }

    boolean searchNode(int key) {
        Node current = head;
        while (current != null) {
            if (current.data == key) {
                return true;
            }
            current = current.next;
        }
        return false;
    }

    void printList() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("null");
    }

    void reverseList() {
        Node prev = null;
        Node current = head;
        Node next = null;
        while (current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    public static void main(String[] args) {
        LinkedList llist = new LinkedList();
        llist.insertAtEnd(1);
        llist.insertAtBeginning(2);
        llist.insertAtEnd(3);
        llist.insertAtPosition(4, 1);

        System.out.println("Linked list after insertion:");
        llist.printList();

        llist.deleteNode(2);
        System.out.println("Linked list after deletion:");
        llist.printList();

        int key = 3;
        if (llist.searchNode(key)) {
            System.out.println(key + " is found in the list.");
        } else {
            System.out.println(key + " is not found in the list.");
        }

        llist.reverseList();
        System.out.println("Linked list after reversal:");
        llist.printList();
    }
}
```

### **Explanation of Commands:**

1. **C Language:**
   - **`malloc(sizeof(struct Node))`**: Allocates memory for a new node.
   - **`free(temp)`**: Frees the memory of the deleted node.
   - **`printf("%d -> ", node->data)`**: Prints the data of the current node.

2. **Python:**
   - **`self.head = new_node`**: Updates the head to point to the new node.
   - **`while last.next:`**: Traverses the list until the last node.
   - **`print(temp.data, end=" -> ")`**: Prints the data of the current node.

3. **Java:**
   - **`new Node(new_data)`**: Creates a new node with the given data.
   - **`while (last.next != null)`**: Traverses the list until the last node.
   - **`System.out.print(temp.data + " -> ")`**: Prints the data of the current node.

These implementations cover all the basic operations on a singly linked list in C, Python, and Java.