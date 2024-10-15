// Class definition
class Box {
    int width;
    int height;

    // Method that takes a Box object as input and returns a new Box object
    Box createBiggerBox(Box originalBox) {
        // Create a new Box object
        Box biggerBox = new Box(); // Declare and initialize new object on separate lines
        biggerBox.width = originalBox.width * 2; // Doubling the width of the new Box
        biggerBox.height = originalBox.height * 2; // Doubling the height of the new Box
        return biggerBox; // Returning the new object
    }
}

public class PassObjectAndReturn {
    public static void main(String[] args) {
        // Declare a Box object
        Box smallBox;

        // Initialize the Box object
        smallBox = new Box();
        smallBox.width = 5; // Set the width of the smallBox
        smallBox.height = 10; // Set the height of the smallBox

        // Create another object to work with the method
        Box biggerBox;

        // Call the method to create a bigger Box by passing the smallBox
        biggerBox = smallBox.createBiggerBox(smallBox); // Method call to return a bigger box

        // Display the dimensions of the bigger Box
        System.out.println("Bigger Box Width: " + biggerBox.width); // Output: 10
        System.out.println("Bigger Box Height: " + biggerBox.height); // Output: 20
    }
}
