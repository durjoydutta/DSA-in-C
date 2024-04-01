import numpy as np

myArray = np.random.randint(-1000, 1000, 500)
# generating a PseudoRandom array of 500 integers
print("The unsorted array is given by : \n", myArray)

print("=*=" * 25)


def selectionSort(arr):
    indexRange = len(arr)
    for i in range(indexRange - 1):  # iterates over the whole array length
        min = i
        for j in range(i + 1, indexRange):  # iterates over the rest of the array
            # print(arr[min],arr[j]) #optional to understand
            if arr[j] < arr[min]:
                min = j
        arr[i], arr[min] = arr[min], arr[i]
        # print(arr) #optional to understand

    return arr


print("The sorted array given by selection sort is: \n", selectionSort(myArray))
