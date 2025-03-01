class Solution:
    def merge(self, arr, low, mid, high):
        temp = []
        l = low
        r = mid + 1

        while l <= mid and r <= high:
            if arr[l] <= arr[r]:
                temp.append(arr[l])
                l += 1
            else:
                temp.append(arr[r])
                r += 1

        while l <= mid:
            temp.append(arr[l])
            l += 1

        while r <= high:
            temp.append(arr[r])
            r += 1

        for i in range(low, high + 1):
            arr[i] = temp[i - low]

    def mergeSort(self, arr, l, r):
        if l >= r:
            return
        mid = (r + l) // 2
        self.mergeSort(arr, l, mid)
        self.mergeSort(arr, mid + 1, r)

        self.merge(arr, l, mid, r)
