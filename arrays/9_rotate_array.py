from typing import List


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.

        [1,2,3,4,5,6,7]

        [7,6,5,4,3,2,1]

        [5,6,7,1,2,3,4]

        """
        n = len(nums)
        k = k % n
        nums.reverse()
        self.helper(nums, 0, k - 1)
        self.helper(nums, k, n - 1)

    def helper(self, arr: list, i: int, j: int) -> list:
        if len(arr) <= 1:
            return arr
        while i < j:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1

        return arr
