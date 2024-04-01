def quickSort(arr, left, right):
    if left < right:
        print
        partition_index = partition(arr, left, right)
        quickSort(arr, left, partition_index - 1)
        quickSort(arr, partition_index + 1, right)
    return arr


# partition the array in such a way that the elements on the left are smaller and on the right larger
def partition(arr, left, right):
    i = left - 1
    pivot = arr[right]

    for j in range(left, right):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # swapping the jth smaller element with larger ith element
    # after this loop, i will be the index of the last smaller element to the pivot
    arr[i + 1], arr[right] = arr[right],arr[i + 1]  # after completing the loop, we insert the pivot to its right position

    return (i + 1)  # return the index of the pivot element after partitioning (partition index)


myArr = [13, 434]
print(quickSort(myArr, 0, len(myArr)-1 ))
