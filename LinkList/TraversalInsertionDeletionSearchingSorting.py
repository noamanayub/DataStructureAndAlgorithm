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