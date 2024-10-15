public class ArrayNameInJAVA {
    public static void main(String[] args) {
        int[] arr = { 10, 20, 30 };

        // Print array reference
        System.out.println("Array reference (arr): " + arr);
        System.out.println("Array reference (identityHashCode): " + System.identityHashCode(arr));

        // Print values of arr[0] and arr[1]
        System.out.println("Value of arr[0]: " + arr[0]);
        System.out.println("Value of arr[1]: " + arr[1]);

        // You can't access memory addresses in Java directly, but array reference is
        // printed
    }
}
