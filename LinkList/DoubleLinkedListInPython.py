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
