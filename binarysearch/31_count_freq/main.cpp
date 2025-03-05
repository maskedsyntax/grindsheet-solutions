#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countFreq(vector<int>& arr, int target) {
        int start = bs(arr, target, true);
        int end = bs(arr, target, false);
        
        // if element is not found, return 0
        if (start == -1 && end == -1) return 0;
        
        // if either either lower_bound or upper_bound is not found:
        // set them to 0 and arr.size()-1 respectively
        if (start == -1) start = 0;
        if (end == -1) end = arr.size()-1;
        
        // return the size of the window
        return end - start + 1;
    }
    
    int bs(vector<int>& arr, int target, bool f) {
        int l = 0, r = arr.size()-1;
        int ans = -1;
        while (l <= r) {
            long long mid = l + (r - l)/2;
            
            // if f is true: 
            // we are finding lower bound of the target
            if (f) {
                if (arr[mid] >= target) {
                    if (arr[mid] == target) ans = mid;
                    r = mid - 1;
                }
                
                else {
                    l = mid + 1;
                }
            }
            
            else {
                if (arr[mid] <= target) {
                    if (arr[mid] == target) ans = mid;
                    l = mid + 1;
                }
                
                else {
                    r = mid - 1;
                }
            }
        }
        
        return ans;
    }
};
