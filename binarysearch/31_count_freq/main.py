class Solution:
    def countFreq(self, arr, target):
        start = self.bs(arr, target, True)
        end = self.bs(arr, target, False)
        
        if start == -1 and end == -1:
            return 0
            
        if start == -1:
            start = 0
        if end == -1:
            end = len(arr)-1
            
        return end - start + 1
    
    
    def bs(self, arr, target, f):
        l, r = 0, len(arr)-1
        ans = -1
        while l <= r:
            mid = l + (r - l)//2
            
            if f:
                if arr[mid] >= target:
                    if arr[mid] == target:
                        ans = mid
                    r = mid - 1
                else: l = mid + 1
                
            else:
                if arr[mid] <= target:
                    if arr[mid] == target:
                        ans = mid
                    l = mid + 1
                else: r = mid - 1
                
        return ans