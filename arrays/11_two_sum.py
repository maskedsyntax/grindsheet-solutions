from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}
        for i in range(len(nums)):
            check = target - nums[i]
            if check in map:
                return [i, map[check]]
            else:
                map[nums[i]] = i

        return []
