from sys import *
from collections import *
from math import *


def getLongestSubarray(nums: list[int], k: int) -> int:
    prefixSumMap = {}
    sum = 0
    ans = 0
    for r in range(len(nums)):
        sum += nums[r]
        if sum == k:
            ans = max(ans, r + 1)
        rem = sum - k
        if rem in prefixSumMap:
            ans = max(ans, r - prefixSumMap[rem])
        if sum not in prefixSumMap:
            prefixSumMap[sum] = r

    return ans
