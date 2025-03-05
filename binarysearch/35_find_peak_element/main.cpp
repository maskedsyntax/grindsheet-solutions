#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if (nums.size() == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n-1] > nums[n-2]) return n-1;

        int l = 1, r = n-2;
        while (l <= r) {
            long long mid = l + (r - l)/2;
            if ((mid > 0 && nums[mid] > nums[mid-1]) && (mid < nums.size()-1 && nums[mid] > nums[mid+1])) {
                return mid;
            }

            else if ((mid > 0 && nums[mid] > nums[mid-1]) && (mid < nums.size()-1 && nums[mid] < nums[mid+1])) {
                l = mid + 1;
            }

            else {
                r = mid -1;
            }
        }

        return 0;
    }
};