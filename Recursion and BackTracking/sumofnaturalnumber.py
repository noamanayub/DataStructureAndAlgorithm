def find_subsets(nums, index, path, result):
    result.append(list(path))
    for i in range(index, len(nums)):
        path.append(nums[i])
        find_subsets(nums, i + 1, path, result)
        path.pop()  # Backtrack

nums = [1, 2, 3]
result = []
find_subsets(nums, 0, [], result)
print(result)  # Output: [[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]]
