from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def util(
            nums: List[int], curr: List[int], idx: int, ans: List[List[int]]
        ) -> None:
            if idx == len(nums):
                ans.append(curr[:])
                return

            # pick
            curr.append(nums[idx])
            util(nums, curr, idx + 1, ans)
            # not pick
            curr.pop()
            util(nums, curr, idx + 1, ans)

        ans = []
        util(nums, [], 0, ans)

        return ans


"""
nums = [1, 2, 3]

[]
[1]
[1, 2]
[1, 2, 3]
[1, 3]
[2]
[2, 3]
[3]

"""
