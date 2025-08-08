from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def util(
            candidates: List[int],
            target: int,
            curr_sum: int,
            curr: List[int],
            idx: int,
            ans: List[List[int]],
        ) -> None:
            if curr_sum >= target:
                if curr_sum == target:
                    ans.append(curr[:])
                return

            if idx >= len(candidates):
                return

            # pick the current element but dont move ahead: we may need this value again
            curr.append(candidates[idx])
            util(candidates, target, curr_sum + candidates[idx], curr, idx, ans)
            # move on bruh!
            curr.pop()
            util(candidates, target, curr_sum, curr, idx + 1, ans)

        ans = []
        util(candidates, target, 0, [], 0, ans)

        return ans


"""
can = [2, 3, 6, 7]
target = 7

curr_sum = 0
[2, 2, 2] -> 6
[2, 2, 3] -> 7
[2,3,3] -> 8
[2,6] -> 8
[2] -> 2

"""
