def gcd(a, b):
    # Base case: If b is 0, then a is the GCD (since any number % 0 is that number)
    if b == 0:
        return a
    else:
        # Recursive case: Calculate gcd(b, a % b)
        return gcd(b, a % b)

# Testing the function
print(gcd(48, 18))  # Output: 6
