from typing import List


class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l, r = 0, len(nums)-1

        if len(nums) == 0: return len(nums)

        while l < r:
            mid = l + (r - l)//2

            if (mid > 0 and nums[mid-1] != nums[mid]) and (mid < len(nums)-1 and nums[mid+1] != nums[mid]):
                return nums[mid]

            # // For each number check left and right
            # // if right exists: it must have an odd index => The single element is in the right half now
            # // if left exists: it must have an even index => The single element is in the right half now
            # // else it is in the left half

            if ((mid > 0 and nums[mid-1] == nums[mid] and ((mid-1)%2 == 0)) 
                or (mid < len(nums)-1 and nums[mid+1] == nums[mid] and ((mid+1)%2 != 0))):
                l = mid + 1
            else: r = mid - 1

        return nums[l]