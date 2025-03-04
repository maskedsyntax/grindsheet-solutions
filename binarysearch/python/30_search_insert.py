class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)-1
        ans = -1
        while l <= r:
            mid = l + (r - l)//2
            print(nums[mid], mid)
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                ans = mid
                r = mid - 1
            else: l = mid + 1

        if ans == -1:
            return len(nums)

        return ans
