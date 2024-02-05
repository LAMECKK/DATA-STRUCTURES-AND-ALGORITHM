# Prompt the user to enter the values of array 'nums'
nums = list(map(int, input("Enter the values of array 'nums' separated by space: ").split()))

# Prompt the user to enter the rotation value 'k'
k = int(input("Enter the rotation value 'k': "))

# Rotate the array to the right by value 'k'
k = k % len(nums)  # Handle the case where k is greater than the length of the array
nums = nums[-k:] + nums[:-k]

# Print the rotated array
print("The rotated array is: ", nums)