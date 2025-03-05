from typing import List


class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)
        if (n == 1): return 0
        if (nums[0] > nums[1]): return 0
        if (nums[n-1] > nums[n-2]): return n-1

        l, r = 1, len(nums)-2
        
        while (l <= r):
            mid = l + (r-l)//2

            if nums[mid] > nums[mid-1] and nums[mid] > nums[mid+1]:
                return mid

            if nums[mid] > nums[mid-1] and nums[mid] < nums[mid+1]:
                l = mid + 1

            else:
                r = mid - 1

        return 0