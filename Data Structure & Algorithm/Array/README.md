## Table of Contents
- [Pointer Example in C](#pointer-example-in-c)
  - [Code Explanation](#code-explanation)
  - [Key Concepts](#key-concepts)
    - [Pointers](#pointers)
    - [Address-of Operator (`&`)](#address-of-operator-)
    - [Dereferencing (`*`)](#dereferencing-)
    - [Size of Data Types](#size-of-data-types)
    - [Data Types and Pointers](#data-types-and-pointers)
  - [Program Output](#program-output)
    - [Example Output](#example-output)
- [Pointer Swap Program in C](#pointer-swap-program-in-c)
  - [Concept Overview](#concept-overview)
  - [Call by Value vs Call by Reference](#call-by-value-vs-call-by-reference)
  - [Swap Function](#swap-function)
  - [Main Function](#main-function)
- [Double Pointer (Pointer in Pointer)](#double-pointer-pointer-in-pointer)
  - [Theory](#theory)
    - [Key Points](#key-points)
    - [Advantages](#advantages)
    - [Disadvantages](#disadvantages)
  - [C Code Example](#c-code-example)
  - [Explanation of the Code](#explanation-of-the-code)
  - [Simulated Output Screen](#simulated-output-screen)


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







# Pointer Swap Program in C

This program demonstrates how to swap the values of two variables using **pointers** in C. It includes a comparison between **Call by Value** and **Call by Reference** to illustrate how passing values and pointers to a function affects the original variables.

## Concept Overview
In this program, the swapping of two variables is done using pointers. Pointers store the **memory addresses** of variables, allowing direct manipulation of their values. When you pass a variable by reference (i.e., its memory address) to a function, any changes made inside the function are reflected in the original variables outside the function.

### Call by Reference
When you pass the address of variables (e.g., `&a`, `&b`) to a function, you are passing them **by reference**. This means that the function can modify the actual values of the variables in the calling function (in this case, the `main` function). This is achieved by accessing and manipulating the values stored at those memory addresses.

### Call by Value vs Call by Reference

| **Call by Value**                             | **Call by Reference**                                |
|-----------------------------------------------|------------------------------------------------------|
| A copy of the variable's value is passed.     | The memory address (reference) of the variable is passed. |
| Changes made in the function do not affect the original variable. | Changes made in the function directly affect the original variable. |
| The original variable remains unchanged.      | The original variable is modified.                   |
| Used when the function only needs the value of the variable. | Used when the function needs to modify the original variable. |

## Pointers in C
A **pointer** is a variable that stores the memory address of another variable. By using pointers, we can manipulate the data stored in that memory location. In this program, `x` and `y` are pointers that store the addresses of `a` and `b`:

```c
void swap(int *x, int *y)
```
Here, `*x` and `*y` are used to access the values of `a` and `b` through their memory addresses.

## Swap Function
The `swap` function is responsible for swapping the values of two variables using pointers:

```c
void swap(int *x, int *y){ 
    int z;
    z = *x;  // Store the value of *x (i.e., a) in z
    *x = *y; // Set *x to the value of *y (i.e., b)
    *y = z;  // Set *y to the original value of *x (stored in z)
}
```
In this function, we:
1. Store the value at memory location `x` in a temporary variable `z`.
2. Assign the value at memory location `y` to the location `x`.
3. Assign the value of `z` to the location `y`.

This swaps the values of `a` and `b`.

## Main Function
The `main` function initializes two variables `a` and `b` and prints their values before and after calling the `swap` function:

```c
int main(){
    int a = 10, b = 20; 
    printf("Before Function Call: a = %d, b = %d\n", a, b);
    swap(&a, &b); // Pass the addresses of 'a' and 'b' to the swap function
    printf("After Function Call: a = %d, b = %d", a, b);
}
```
Before calling `swap`, `a` is 10 and `b` is 20. After calling `swap`, their values are exchanged because the function modifies the variables directly through pointers.







# Double Pointer (Pointer in Pointer)

## Theory

A **double pointer**, often referred to as a pointer to a pointer, is a variable that holds the address of another pointer. This concept allows for multi-level indirection in memory, enabling us to reference variables in multiple layers. 

### Key Points:
- **Definition**: A double pointer is declared using two asterisks (`**`). For example, `int **p2` is a double pointer that can point to an integer pointer (`int *p`).
- **Memory Levels**: In a typical scenario, we have:
  - A variable `a` of type `int`.
  - A pointer `p` that stores the address of `a` (i.e., `p = &a`).
  - A double pointer `p2` that stores the address of `p` (i.e., `p2 = &p`).
  
This structure is useful in various scenarios, including:
- **Dynamic Memory Allocation**: When working with arrays of pointers, such as a 2D array, a double pointer allows for easier management of memory.
- **Data Structures**: In complex data structures like linked lists, trees, and graphs, double pointers help maintain connections between nodes.

### Advantages:
- **Flexibility**: Double pointers provide greater flexibility in managing complex data structures.
- **Dynamic Changes**: They enable dynamic changes to the structure and elements of data (e.g., resizing arrays).

### Disadvantages:
- **Complexity**: Working with multiple levels of pointers can make code harder to read and debug.
- **Overhead**: More indirection may introduce slight performance overhead in certain situations.

---

## C Code Example

Here’s a simple C program that demonstrates the use of double pointers:

```c
#include <stdio.h>

int main() {
    int a = 10;        // Variable a holds the value 10
    int *p = &a;       // p is a pointer to the address of a
    int **p2 = &p;     // p2 is a pointer to the address of p (a pointer to a pointer)

    // Print values
    printf("Value of a: %d\n", a);              // Value of a
    printf("Address of a (&a): %p\n", &a);      // Address of a
    printf("Value at the address of a (*(&a)): %d\n", *(&a)); // Value of a through address of a
    printf("Value of p (address of a): %p\n", p);  // Address of a stored in p
    printf("Value pointed to by p (*p): %d\n", *p); // Value of a via p
    printf("Address of p (&p): %p\n", &p);      // Address of p
    printf("Value of p2 (address of p): %p\n", p2); // Address of p stored in p2
    printf("Value pointed to by p2 (*p2): %p\n", *p2); // Address of a via p2
    printf("Value pointed to by *p2 (**p2): %d\n", **p2); // Value of a via p2

    return 0;
}
```

### Explanation of the Code:

1. **Variable Declaration**:
   - `int a = 10;` initializes the integer variable `a` with the value `10`.
   - `int *p = &a;` creates a pointer `p` that points to the address of `a`.
   - `int **p2 = &p;` creates a double pointer `p2` that points to the address of `p`.

2. **Printing Values and Addresses**:
   - The program uses `printf` to display the value of `a`, the addresses of `a`, `p`, and the values pointed to by `p` and `p2`.
   - This demonstrates how pointers interact with each other and how we can access values through multiple levels of pointers.

### Simulated Output Screen

Assuming the addresses are as follows:
- Address of `a`: `0x2001`
- Address of `p`: `0x3001`
- Address of `p2`: `0x4001`

The output would look like this:

```
Value of a: 10
Address of a (&a): 0x2001
Value at the address of a (*(&a)): 10
Value of p (address of a): 0x2001
Value pointed to by p (*p): 10
Address of p (&p): 0x3001
Value of p2 (address of p): 0x4001
Value pointed to by p2 (*p2): 0x2001
Value pointed to by *p2 (**p2): 10
```
