def removeDuplicates(nums):
    if len(nums) == 0:
        return 0
    i = 0
    for j in range(1, len(nums)):
        if nums[j] != nums[i]:
            i += 1
            nums[i] = nums[j]
    return i + 1

# Prompt user to input array values
nums = list(map(int, input("Enter sorted array values separated by space: ").split()))

# Remove duplicates in-place and get new length
new_length = removeDuplicates(nums)

# Print out the sorted array without duplicates
print("Sorted array without duplicates:", nums[:new_length])
print("New length:", new_length)