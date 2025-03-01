class Solution:
    def insertionSort(self, arr):
        for i in range(1, len(arr)):
            key = arr[i]
            x = i - 1
            while x >= 0 and arr[x] > key:
                arr[x + 1] = arr[x]
                x -= 1

            arr[x + 1] = key
