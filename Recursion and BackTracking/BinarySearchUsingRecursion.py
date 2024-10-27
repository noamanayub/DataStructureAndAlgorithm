def binary_search(arr, low, high, x):
    # Base case: If the search range is exhausted, return -1 (element not found)
    if high < low:
        return -1

    # Calculate the middle index
    mid = (low + high) // 2

    # Check if the middle element is the target
    if arr[mid] == x:
        return mid
    # If the target is less than the middle element, search in the left half
    elif arr[mid] > x:
        return binary_search(arr, low, mid - 1, x)
    # If the target is greater than the middle element, search in the right half
    else:
        return binary_search(arr, mid + 1, high, x)

# Testing the function
arr = [1, 2, 3, 4, 5, 6, 7]
x = 5
result = binary_search(arr, 0, len(arr) - 1, x)
print(f"Element found at index {result}")  # Output: Element found at index 4
