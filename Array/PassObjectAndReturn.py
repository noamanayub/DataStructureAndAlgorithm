# Class definition
class Box:
    def __init__(self, width, height):
        # Initialize the Box object with width and height
        self.width = width
        self.height = height

    # Method that takes a Box object and returns a new Box object
    def create_bigger_box(self, original_box):
        # Create a new Box object with doubled dimensions
        bigger_box = Box(original_box.width * 2, original_box.height * 2)
        return bigger_box  # Return the new Box object


# Main code
# Declare and initialize the original small Box object
small_box = Box(5, 10)  # Box with width 5 and height 10

# Call the method to create a bigger box by passing small_box
bigger_box = small_box.create_bigger_box(small_box)

# Display the dimensions of the bigger Box
print(f"Bigger Box Width: {bigger_box.width}")  # Output: 10
print(f"Bigger Box Height: {bigger_box.height}")  # Output: 20
