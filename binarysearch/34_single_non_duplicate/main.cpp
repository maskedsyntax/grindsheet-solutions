#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        if (nums.size() == 1) return nums[0];

        int l = 0, r = nums.size() - 1;

        // 0 1 2 3 4 5 6 7 8
        // 1 1 2 3 3 4 4 8 8

        // 0 1 2 3 4 5 6 7 8
        // 1 1 2 2 3 3 4 8 8

        // Before single element:
        // Every number has two indices: first is even, second is odd
        // After single element:
        // Two indices: first is odd, second is even

        // For each number check left and right
        // if right exists: it must have an odd index => The single element is in the right half now
        // if left exists: it must have an even index => The single element is in the right half now
        // else it is in the left half

        while (l < r) {
            long long mid = l + (r - l)/2;

            int ridx = mid + 1;
            int lidx = mid - 1;

            if ((mid > 0 && nums[mid-1] != nums[mid]) && (mid+1 < nums.size() && nums[mid] != nums[mid+1])) {
                return nums[mid];
            }

            if ((mid < nums.size()-1 && nums[mid+1] == nums[mid] && ((mid + 1) % 2 != 0)) 
                    || (mid > 0 && nums[mid-1] == nums[mid] && ((mid - 1) % 2 == 0)))
            {
                l = mid + 1;
            }
            else 
            {
                r = mid - 1;
            }
        }

        return nums[l];

    }
};