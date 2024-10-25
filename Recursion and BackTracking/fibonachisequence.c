#include <stdio.h>

int fibonacci(int n) {
    if (n == 0)  // Base case
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive call
}

int main() {
    printf("%d\n", fibonacci(5));  // Output: 5
    return 0;
}
