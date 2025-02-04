def longestSubarrayWithSumK(a: list, k: int) -> int:
    prefixSumMap = {0: 1}
    sum = 0
    ans = 0
    for r in range(len(a)):
        sum += a[r]
        rem = sum - k
        if rem in prefixSumMap:
            ans = max(ans, r - prefixSumMap[rem])
        if sum not in prefixSumMap:
            prefixSumMap[sum] = r
    return ans
