class AVLNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        self.height = 1

def height(node):
    if node is None:
        return 0
    return node.height

def balance_factor(node):
    if node is None:
        return 0
    return height(node.left) - height(node.right)

def rotate_right(y):
    x = y.left
    T2 = x.right

    x.right = y
    y.left = T2

    y.height = max(height(y.left), height(y.right)) + 1
    x.height = max(height(x.left), height(x.right)) + 1

    return x

def rotate_left(x):
    y = x.right
    T2 = y.left

    y.left = x
    x.right = T2

    x.height = max(height(x.left), height(x.right)) + 1
    y.height = max(height(y.left), height(y.right)) + 1

    return y

def insert_avl(root, value):
    if root is None:
        return AVLNode(value)
    if value < root.value:
        root.left = insert_avl(root.left, value)
    else:
        root.right = insert_avl(root.right, value)

    root.height = 1 + max(height(root.left), height(root.right))

    balance = balance_factor(root)

    if balance > 1 and value < root.left.value:
        return rotate_right(root)
    if balance < -1 and value > root.right.value:
        return rotate_left(root)
    if balance > 1 and value > root.left.value:
        root.left = rotate_left(root.left)
        return rotate_right(root)
    if balance < -1 and value < root.right.value:
        root.right = rotate_right(root.right)
        return rotate_left(root)

    return root

# Example usage
root = None
root = insert_avl(root, 10)
root = insert_avl(root, 20)
root = insert_avl(root, 30)