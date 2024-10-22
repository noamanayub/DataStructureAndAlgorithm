class CircularQueue:
    def __init__(self, size):
        """Initialize the queue with a fixed size"""
        self.size = size
        self.queue = [None] * size  # Initialize the queue with None
        self.front = -1  # Front pointer
        self.rear = -1   # Rear pointer

    def is_full(self):
        """Check if the queue is full"""
        return (self.front == (self.rear + 1) % self.size)

    def is_empty(self):
        """Check if the queue is empty"""
        return self.front == -1

    def enqueue(self, value):
        """Insert an element into the circular queue"""
        if self.is_full():
            print("Queue is full!")
        else:
            # If inserting the first element, set front to 0
            if self.front == -1:
                self.front = 0
            
            # Move rear to the next position in a circular way
            self.rear = (self.rear + 1) % self.size
            self.queue[self.rear] = value
            print(f"Inserted {value}")

    def dequeue(self):
        """Remove and return an element from the circular queue"""
        if self.is_empty():
            print("Queue is empty!")
            return None
        else:
            value = self.queue[self.front]  # Get the front element
            
            # If there's only one element, reset the queue
            if self.front == self.rear:
                self.front = -1
                self.rear = -1
            else:
                # Move front to the next position in a circular way
                self.front = (self.front + 1) % self.size
            print(f"Deleted {value}")
            return value

    def display(self):
        """Display the elements of the queue"""
        if self.is_empty():
            print("Queue is empty!")
        else:
            print("Queue elements:", end=" ")
            i = self.front
            while i != self.rear:
                print(self.queue[i], end=" ")
                i = (i + 1) % self.size
            print(self.queue[i])  # Print the last element (rear)


# Test the CircularQueue class
if __name__ == "__main__":
    cq = CircularQueue(5)  # Initialize queue of size 5

    cq.enqueue(10)
    cq.enqueue(20)
    cq.enqueue(30)
    cq.enqueue(40)
    cq.enqueue(50)  # This will fill the queue

    cq.display()  # Display the queue
    
    cq.dequeue()  # Remove an element
    cq.dequeue()  # Remove another element
    
    cq.display()  # Display the queue after deletion
    
    cq.enqueue(60)  # Insert new element
    cq.display()  # Display the updated queue
