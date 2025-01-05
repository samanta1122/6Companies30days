#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0, j = 0, count = 0, result = 0, prefix = 0;

        while (j < nums.size()) {
            if (nums[j] % 2 == 1) {
                count++;
                prefix = 0;
            }
            while (count > k) {
                if (nums[i] % 2 == 1) {
                    count--;
                }
                i++;
            }
            if (count == k) {
                while (i < nums.size() && nums[i] % 2 == 0) {
                    prefix++;
                    i++;
                }
                result += prefix + 1;
            }
            j++;
        }

        return result;
    }
};