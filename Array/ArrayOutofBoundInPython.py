def out_of_bounds_example():
    i = 5                     # Size of the list
    arr = [0] * i             # Declare a list of size 5

    # Initialize the list
    arr[0] = 10
    arr[1] = 20
    arr[2] = 30
    arr[3] = 40
    arr[4] = 50

    # Attempting to access an out-of-bounds index
    try:
        print(f"Value at arr[9]: {arr[9]}")  # This will raise an IndexError
    except IndexError as e:
        print(f"IndexError: {e}")

    # Print the values of the list
    for j in range(len(arr)):
        print(f"arr[{j}] = {arr[j]}")

if __name__ == "__main__":
    out_of_bounds_example()
