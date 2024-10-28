def tower_of_hanoi(n, source, target, auxiliary):
    # Base case: If only one disk, move it directly from source to target
    if n == 1:
        print(f"Move disk 1 from {source} to {target}")
        return
    else:
        # Step 1: Move n-1 disks from source to auxiliary using target as a helper
        tower_of_hanoi(n - 1, source, auxiliary, target)
        
        # Step 2: Move the nth disk from source to target
        print(f"Move disk {n} from {source} to {target}")
        
        # Step 3: Move the n-1 disks from auxiliary to target using source as a helper
        tower_of_hanoi(n - 1, auxiliary, target, source)

# Testing the function with 3 disks
tower_of_hanoi(3, 'A', 'C', 'B')
