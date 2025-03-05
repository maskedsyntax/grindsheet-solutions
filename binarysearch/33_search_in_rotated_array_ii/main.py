from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        start, end = 0, len(nums) - 1

        while start <= end:
            mid = start + (end - start)//2

            if nums[mid] == target: return True

            if nums[mid] == nums[start] and nums[mid] == nums[end]:
                start += 1
                end -= 1
                continue

            # Left half
            if nums[mid] >= nums[start]:
                if target >= nums[start] and nums[mid] > target:
                    end = mid - 1
                else: start = mid + 1

            # Right half
            else:
                if target <= nums[end] and nums[mid] < target:
                    start = mid + 1
                else: end = mid -1

        return False