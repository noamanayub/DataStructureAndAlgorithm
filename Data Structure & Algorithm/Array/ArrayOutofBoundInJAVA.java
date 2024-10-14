public class ArrayOutofBoundInJAVA {
    public static void main(String[] args) {
        int i = 5; // Size of the array
        int[] arr = new int[i]; // Declare an array of size 5

        // Initialize the array
        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        arr[3] = 40;
        arr[4] = 50;

        // Attempting to access an out-of-bounds index
        try {
            System.out.println("Value at arr[9]: " + arr[9]); // This will throw an exception
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("ArrayIndexOutOfBoundsException: " + e.getMessage());
        }

        // Print the values of the array
        for (int j = 0; j < arr.length; j++) {
            System.out.println("arr[" + j + "] = " + arr[j]);
        }
    }
}
