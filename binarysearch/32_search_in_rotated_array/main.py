from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        start, end = 0, len(nums)-1

        while start <= end:
            mid = start + (end - start)//2

            if nums[mid] == target:
                return mid

            # Check the left sorted part
            if nums[mid] >= nums[start]:
                if target >= nums[start] and nums[mid] > target:
                    end = mid - 1
                else:
                    start = mid + 1

            # Check the right sorted part
            else:
                if target <= nums[end] and nums[mid] < target:
                    start = mid + 1
                else:
                    end = mid - 1

        return -1