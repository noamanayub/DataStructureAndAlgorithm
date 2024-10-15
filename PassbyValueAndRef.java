class Test {
    void modifyValue(int num) {
        num = 10; // This will not affect the original variable
    }

    void modifyObject(Box b) {
        b.width = 50; // This will modify the original object
    }
}

public class PassbyValueAndRef {
    public static void main(String[] args) {
        // Pass by value for primitive type
        int number = 5;
        Test test = new Test();
        test.modifyValue(number);
        System.out.println(number); // Output: 5 (unchanged)

        // Pass by reference for object
        Box box = new Box();
        box.width = 20;
        test.modifyObject(box);
        System.out.println(box.width); // Output: 50 (modified)
    }
}
