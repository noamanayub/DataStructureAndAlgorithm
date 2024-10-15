#include <stdio.h>

int main() {
    int arr[3] = {10, 20, 30};

    // Print array name (it represents a constant pointer to the first element)
    printf("Array name (arr): %p\n", arr);       // Prints the address of the first element

    /*
    'arr' (array name) is worked like a constant pointer. 'arr' don't take separate space in memory its a label.
    Acts as a constant pointer to the first element (arr[0]). It doesn't take up separate memory, but is a
    symbolic reference used by the compiler. Think of arr as a label stuck to a memory location. The label always
    points to the first element of the array, and while you can move through the array with pointer arithmetic,
    you can never remove or change that label itself. It's permanently attached to the starting address.
    */

    // Dereferencing arr (equivalent to arr[0])
    printf("Dereferenced value (*arr): %d\n", *arr);  // Prints value of arr[0]

    // Print address of the array itself using & operator
    printf("Address of the array (&arr): %p\n", (void*)&arr);  // Prints address of the entire array

    // Print values of arr[0] and arr[1]
    printf("Value of arr[0]: %d\n", arr[0]);
    printf("Value of arr[1]: %d\n", arr[1]);

    // Print the addresses without using & operator (array name already acts as a pointer)
    printf("Address of arr[0]: %p\n", arr);        // Same as &arr[0]
    printf("Address of arr[1]: %p\n", arr + 1);    // Same as &arr[1]

    return 0;
}
