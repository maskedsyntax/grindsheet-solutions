#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int start = 0, end = nums.size() - 1;
    
            while (start <= end) {
                long long mid = start + (end - start) / 2;
    
                if (nums[mid] == target) return true;
    
                if (nums[mid] == nums[start] && nums[mid] == nums[end]) {
                    start++;
                    end--;
                    continue;
                }
    
                // left half is sorted
                if (nums[mid] >= nums[start]) {
                    if (target >= nums[start] && nums[mid] > target) {
                        end = mid - 1;
                    } else {
                        start = mid + 1;
                    }
                }
                // right half is sorted
                else {
                    if (target <= nums[end] && nums[mid] < target) {
                        start = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
            }
    
            return false;
        }
    };