import java.util.ArrayList;

class Queue {
    private ArrayList<Integer> items;

    public Queue() {
        items = new ArrayList<>();
    }

    public boolean isEmpty() {
        return items.isEmpty();
    }

    public void enqueue(int item) {
        items.add(item);
    }

    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Queue Underflow");
            return -1; // Assuming -1 as an error code
        }
        return items.remove(0);
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("Queue is Empty");
            return -1; // Assuming -1 as an error code
        }
        return items.get(0);
    }

    public static void main(String[] args) {
        Queue queue = new Queue();
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);

        System.out.println("Front element: " + queue.peek());

        System.out.println("Dequeued element: " + queue.dequeue());
        System.out.println("Dequeued element: " + queue.dequeue());

        System.out.println("Front element: " + queue.peek());
    }
}