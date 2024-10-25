#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1)  // Base case
        return 1;
    else
        return n * factorial(n - 1);  // Recursive call
}

int main() {
    printf("%d\n", factorial(5));  // Output: 120
    return 0;
}
