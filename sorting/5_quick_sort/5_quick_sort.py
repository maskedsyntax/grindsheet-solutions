class Solution:
    # Function to sort a list using quick sort algorithm.
    def quickSort(self, arr, low, high):
        if low < high:
            pivotIdx = self.partition(arr, low, high)
            self.quickSort(arr, low, pivotIdx - 1)
            self.quickSort(arr, pivotIdx + 1, high)

    def partition(self, arr, low, high):
        pivot = arr[low]
        i = low
        j = high

        while i < j:
            while arr[i] <= pivot and i < high:
                i += 1

            while arr[j] > pivot and j > low:
                j -= 1

            if i < j:
                arr[i], arr[j] = arr[j], arr[i]

        arr[j], arr[low] = arr[low], arr[j]

        return j
