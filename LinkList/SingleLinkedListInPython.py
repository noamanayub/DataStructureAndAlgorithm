# Define the Node class to represent each element of the linked list
class Node:
    def __init__(self, data):
        self.data = data   # Store the data (integer) in the node
        self.next = None   # Initialize the next pointer as None (end of the list)

# Define the LinkedList class to manage the nodes
class LinkedList:
    def __init__(self):
        self.head = None   # Initially, the linked list is empty, so the head is None

    # Function to add data to the list (create nodes)
    def add(self, data):
        new_node = Node(data)     # Create a new node with the given data
        if self.head is None:     # If the list is empty, the new node becomes the head
            self.head = new_node
        else:
            # Traverse the list and add the new node at the end
            temp = self.head
            while temp.next is not None:  # Move to the last node
                temp = temp.next
            temp.next = new_node  # Link the last node to the new node

    # Function to print the linked list
    def print_list(self):
        temp = self.head   # Start from the head node
        while temp is not None:
            print(temp.data, end=" -> ")  # Print the data of the current node
            temp = temp.next   # Move to the next node
        print("None")  # End of the list


# Main part of the code to create the linked list
if __name__ == "__main__":
    # Create an instance of LinkedList
    linked_list = LinkedList()

    # Add 5 nodes with random data
    linked_list.add(10)
    linked_list.add(20)
    linked_list.add(30)
    linked_list.add(40)
    linked_list.add(50)

    # Print the linked list
    linked_list.print_list()
