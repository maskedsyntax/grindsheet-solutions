class Solution:
    # Function to sort the array using bubble sort algorithm.
    def bubbleSort(self, arr):
        for i in range(0, len(arr) - 1):
            for j in range(i + 1, len(arr)):
                if arr[j] < arr[i]:
                    arr[j], arr[i] = arr[i], arr[j]
