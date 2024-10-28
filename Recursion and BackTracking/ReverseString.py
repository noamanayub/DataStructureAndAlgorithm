def reverse_string(s):
    # Base case: If the string is empty or a single character, return it as-is
    if len(s) <= 1:
        return s
    else:
        # Recursive case: Take the last character and add the result of reversing the remaining string
        return s[-1] + reverse_string(s[:-1])

# Testing the function
print(reverse_string("hello"))  # Output: "olleh"
