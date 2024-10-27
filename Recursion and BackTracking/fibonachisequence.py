def fibonacci(n):
    if n == 0:  # Base case
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)  # Recursive call

print(fibonacci(5))  # Output: 5
