from collections import deque

# Create a deque
dq = deque()

# Add elements to the rear
dq.append(10)
dq.append(20)

# Add elements to the front
dq.appendleft(30)
dq.appendleft(40)

# Print deque
print("Deque after adding elements:", dq)

# Remove elements from the rear
dq.pop()

# Remove elements from the front
dq.popleft()

# Print deque after removals
print("Deque after removing elements:", dq)

# Access the front and rear elements
print("Front element:", dq[0])
print("Rear element:", dq[-1])
