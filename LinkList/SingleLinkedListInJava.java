// Node class to represent each element of the linked list
class Node {
    int data; // Data stored in the node
    Node next; // Pointer to the next node

    // Constructor to initialize the node with data and next set to null
    public Node(int data) {
        this.data = data; // Assign data to the node
        this.next = null; // Initially, next is null (no link to another node)
    }
}

// SingleLinkedListInJava class to manage the linked list
public class SingleLinkedListInJava {
    Node head; // Head of the linked list

    // Constructor to initialize an empty list (head is null)
    public SingleLinkedListInJava() {
        head = null;
    }

    // Method to add a new node to the linked list
    public void add(int data) {
        Node newNode = new Node(data); // Create a new node
        if (head == null) {
            head = newNode; // If the list is empty, set the head to the new node
        } else {
            Node temp = head; // Temporary pointer to traverse the list
            while (temp.next != null) {
                temp = temp.next; // Move to the last node
            }
            temp.next = newNode; // Link the last node to the new node
        }
    }

    // Method to print the linked list
    public void printList() {
        Node temp = head; // Start from the head node
        while (temp != null) {
            System.out.print(temp.data + " -> "); // Print the data of the current node
            temp = temp.next; // Move to the next node
        }
        System.out.println("null"); // End of the list
    }

    // Main method to test the linked list
    public static void main(String[] args) {
        SingleLinkedListInJava linkedList = new SingleLinkedListInJava(); // Create an instance of the linked list

        // Add 5 nodes with random data
        linkedList.add(10);
        linkedList.add(20);
        linkedList.add(30);
        linkedList.add(40);
        linkedList.add(50);

        // Print the linked list
        linkedList.printList();
    }
}
