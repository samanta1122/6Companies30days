#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int total = 0;
        for (int start = 0; start < nums.size(); start++) {
        for (int end = start; end < nums.size(); end++) {
            bool isValid = true;
            int maxVal = -1;

            // Check the left portion of the array
            for (int left = 0; left < start; left++) {
                if (nums[left] <= maxVal) {
                    isValid = false;
                    break;
                }
                maxVal = nums[left];
            }

            // Check the right portion of the array
            for (int right = end + 1; right < nums.size(); right++) {
                if (nums[right] <= maxVal) {
                    isValid = false;
                    break;
                }
                maxVal = nums[right];
            }

            // Increment count if the subarray is valid
            total += isValid;
        }
    }

    return total;
    }
};