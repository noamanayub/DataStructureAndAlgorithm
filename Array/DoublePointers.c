#include <stdio.h>

int main() {
    int a = 10;        // a is an integer variable with a value of 10
    int *p = &a;       // p is a pointer to the address of a
    int **p2 = &p;     // p2 is a pointer to the address of p (a pointer to a pointer)

    // Print the values
    printf("Value of a: %d\n", a);              // Prints value of a
    printf("Address of a (&a): %p\n", &a);      // Prints address of a
    printf("Value at the address of a (*(&a)): %d\n", *(&a)); // Dereference address of a to get value of a
    printf("Value of p (address of a): %p\n", p);  // Prints the address stored in p (which is the address of a)
    printf("Value pointed to by p (*p): %d\n", *p); // Dereferences p to get the value of a
    printf("Address of p (&p): %p\n", &p);      // Prints the address of pointer p
    printf("Value of p2 (address of p): %p\n", p2); // Prints the address stored in p2 (which is the address of p)
    printf("Value pointed to by p2 (*p2): %p\n", *p2); // Dereferences p2 to get the value of p (which is the address of a)
    printf("Value pointed to by *p2 (**p2): %d\n", **p2); // Dereferences p2 twice to get the value of a

    return 0;
}
