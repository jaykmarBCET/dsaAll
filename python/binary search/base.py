import array

def binarySearch(arr: array.array, key: int):
    start = 0
    end = len(arr) - 1  

    while start <= end:
        mid = start + (end - start) // 2  
        
        if arr[mid] == key:
            return mid
        elif arr[mid] < key:
            start = mid + 1
        else:
            end = mid - 1

    return -1  # Element not found

arr = array.array('i', [1, 2, 3, 4, 5, 6, 7])
print(binarySearch(arr, 6))  # Output: 5
