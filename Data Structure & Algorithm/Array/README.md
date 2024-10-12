# Pointer Example in C

This is a simple C program that demonstrates how pointers work in C. It explains the concept of pointers, address-of (`&`) operator, dereferencing (`*`) operator, and how to manipulate memory addresses.

## Code Explanation

```c
#include <stdio.h>

int main() {
    int a = 20;
    int *p; // Declare a pointer by using the * operator

    // Store the address of 'a' in pointer variable 'p'
    p = &a;

    /*
    For example: If the address of 'a' is '2001' and the address of 'p' is '3001',
    and 'p' stores 'a''s address, it means 'p = 2001'. So, 'p' is pointing towards 'a' in memory ('p -> a').
    */

    // Print the address of 'a' using the & operator
    printf("Address of a: %p", &a);

    // Print the value of 'a', which is '20' in this case
    printf("\nValue of a: %d", a);

    // Print the address of 'p'
    printf("\nAddress of p: %p", &p);

    // Print the value of 'p', which is the address of 'a'
    printf("\nValue of p: %p", p);

    // Dereference the pointer, meaning it prints the value of 'a' which is '20' in this case
    printf("\nDereferenced value of p: %d", *p);

    /*
    - '&' is used to print the address of a variable.
    - '*' is used to declare a pointer and to print the value at the address (dereferencing).
    - Using * and & together, e.g., *(&a), gives the value stored at the address of 'a'.
    */
}
```

## Key Concepts

### Pointers
A pointer is a variable that stores the memory address of another variable. The `*` symbol is used to declare a pointer. Pointers allow us to work directly with memory addresses, which is useful for memory management and manipulating variables in functions.

### Address-of Operator (`&`)
The `&` operator is used to get the memory address of a variable. For example, `&a` returns the memory address where `a` is stored.

### Dereferencing (`*`)
Dereferencing a pointer means accessing the value stored at the address the pointer is pointing to. For example, `*p` returns the value of `a` since `p` holds the address of `a`.

### Size of Data Types
In a 16-bit compiler, different data types take up different amounts of memory:

- `int` takes 2 bytes.
- `float` takes 4 bytes.
- `char` takes 1 byte.
- `double` takes 8 bytes.

However, when using pointers, regardless of the data type they point to (`int`, `float`, `double`, `char`), the pointer itself always takes a fixed size because it stores an address. In a 16-bit compiler, this size is 2 bytes since memory addresses are always whole numbers.

### Data Types and Pointers:
- **int pointer**: Stores the address of an `int` variable.
- **float pointer**: Stores the address of a `float` variable.
- **double pointer**: Stores the address of a `double` variable.
- **char pointer**: Stores the address of a `char` variable.

All pointers take the same amount of memory because they store memory addresses.

## Program Output

The program demonstrates how to:
- Print the address of a variable.
- Print the value of the variable using pointers.
- Access the value of a variable by dereferencing a pointer.

### Example Output
```
Address of a: 0x7ffc2f4c9a3c
Value of a: 20
Address of p: 0x7ffc2f4c9a40
Value of p: 0x7ffc2f4c9a3c
Dereferenced value of p: 20
```