from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []

        def util(n: int, curr: str, open: int, close: int) -> None:
            if len(curr) == 2 * n:
                ans.append(curr)
                return

            if open > close:
                if open < n:
                    util(n, curr + "(", open + 1, close)
                if close < n:
                    util(n, curr + ")", open, close + 1)
            else:
                if open < n:
                    util(n, curr + "(", open + 1, close)

        util(n, "", 0, 0)
        return ans


"""
open close
n = 3
open > close: any bracket possible
open = 2
close = 1
()(
()((
()()

close == open: only open
close = 2
open = 1
()(

no. of open brackets > close

"""
