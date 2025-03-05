#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int start = 0, end = nums.size() - 1;
            // int ans = -1;
            while (start <= end) {
                long long mid = start + (end - start)/2;
    
                if (nums[mid] == target) return mid;
    
                if (nums[mid] >= nums[start]) {
                    // Check the left sorted part
                    if (target >= nums[start] && nums[mid] > target) {
                        end = mid - 1;
                    } else {
                        start = mid + 1;
                    }
                }
                else {
                    // Check the right sorted part
                    if (target <= nums[end] && nums[mid] < target) {
                        start = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
            }
    
            return -1;
        }
    };