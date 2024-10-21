class Queue:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        if self.is_empty():
            print("Queue Underflow")
            return None
        return self.items.pop(0)

    def peek(self):
        if self.is_empty():
            print("Queue is Empty")
            return None
        return self.items[0]

# Example usage
queue = Queue()
queue.enqueue(10)
queue.enqueue(20)
queue.enqueue(30)

print("Front element:", queue.peek())

print("Dequeued element:", queue.dequeue())
print("Dequeued element:", queue.dequeue())

print("Front element:", queue.peek())