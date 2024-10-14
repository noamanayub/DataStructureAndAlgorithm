#include <stdio.h>

int main() {
    int i = 5;               // Size of the array
    int arr[i];             // Declare a variable-length array of size i

    // Initialize the array
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    /*
    In C, declaring an array with a variable size using int arr[i]; is allowed as of the C99 standard,
    which introduced variable-length arrays (VLAs). However, it is crucial to note that accessing
    an out-of-bounds index, such as arr[9] in this example when the size of arr is only 5, does not throw an error.
    Instead, it leads to undefined behavior because C does not perform bounds checking on array accesses.
    The programmer must ensure that they only access valid indices.
    */

    // Attempting to access an out-of-bounds index
    printf("Value at arr[9]: %d\n", arr[9]); // This will lead to undefined behavior

    /*
    In C, accessing an out-of-bounds index does not produce an error or exception. Instead, it leads to undefined behavior.
    This means that the program may continue running, and you may receive garbage values or even overwrite adjacent memory.
    The lack of built-in error handling means that the programmer must be diligent about managing array bounds manually.
    */

    return 0;
}
