class PriorityQueue:
    def __init__(self):
        """Initialize an empty priority queue"""
        self.queue = []

    def is_empty(self):
        """Check if the queue is empty"""
        return len(self.queue) == 0

    def enqueue(self, value, priority):
        """Insert an element into the priority queue with a given priority"""
        # Insert the element as a tuple (priority, value)
        self.queue.append((priority, value))
        # Sort the queue by priority (ascending order)
        self.queue.sort(key=lambda x: x[0])
        print(f"Inserted {value} with priority {priority}")

    def dequeue(self):
        """Remove and return the element with the highest priority"""
        if self.is_empty():
            print("Queue is empty!")
            return None
        # Remove the element with the highest priority (lowest priority number)
        element = self.queue.pop(0)
        print(f"Deleted {element[1]}")
        return element[1]

    def display(self):
        """Display the elements of the priority queue"""
        if self.is_empty():
            print("Queue is empty!")
        else:
            print("Queue elements with priorities:", end=" ")
            for priority, value in self.queue:
                print(f"{value}(p{priority})", end=" ")
            print()


# Test the PriorityQueue class
if __name__ == "__main__":
    pq = PriorityQueue()

    pq.enqueue(10, 2)
    pq.enqueue(20, 1)
    pq.enqueue(30, 3)
    pq.enqueue(40, 0)

    pq.display()  # Display the queue
    
    pq.dequeue()  # Remove the highest priority element
    pq.dequeue()  # Remove the next highest priority element
    
    pq.display()  # Display the queue after deletion
