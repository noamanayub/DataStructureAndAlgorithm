#include <stdio.h>

// Define a structure
struct Person {
    char name[50];
    int age;
};

// Function to modify structure values by reference (pass by pointer)
void modifyPerson(struct Person *p) {
    // Modifying the values of the structure using pointer
    // *p means we are accessing the actual structure in memory (not a copy)
    printf("Modifying values...\n");
    
    // Changing name and age using the pointer
    // Here, p->name and p->age are equivalent to (*p).name and (*p).age
    // We are modifying the actual values stored in memory
    sprintf(p->name, "Alice");  // Changing the name to "Alice"
    p->age = 30;  // Changing the age to 30
}

int main() {
    // Create a structure variable and initialize it
    struct Person person1 = {"John", 25};

    // Print original values
    printf("Before modification: Name = %s, Age = %d\n", person1.name, person1.age);

    // Pass structure by reference to the function
    modifyPerson(&person1);

    // Print modified values
    // The values are modified because the structure was passed by reference (pointer)
    printf("After modification: Name = %s, Age = %d\n", person1.name, person1.age);

    return 0;
}
