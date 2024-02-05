def findSingle():
    n = int(input("Enter the size of the array: "))
    nums = list(map(int, input("Enter the elements of the array: ").split()))
    if n % 2 != 0:
        print("The array size must be even.")
        return
    result = 0
    for num in nums:
        result ^= num
    print("The single element is: ", result)

findSingle()