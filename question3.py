def has_duplicates():
    """
    Function to check if an array contains any duplicates.
    """
    # Prompt the user to enter their array values
    user_arr = input("Enter your array values separated by space: ")
    # Convert the user input into a list of integers
    arr = list(map(int, user_arr.split()))
    
    # Check if the array contains any duplicates
    if len(arr) != len(set(arr)):
        return True
    return False