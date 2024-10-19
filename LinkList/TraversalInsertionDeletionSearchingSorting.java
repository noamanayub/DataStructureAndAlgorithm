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