#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int length = nums.size();
        int result = 0;
        int median = helper(nums, 0, length - 1, (length - 1) / 2);
        for (int x : nums) {
            result += std::abs(x - median);
        }
        return result;
    }
    private:
    int helper(std::vector<int>& q, int l, int r, int k) {
        if (l >= r) 
            return q[r];
        
        int x = q[(l + r) / 2];
        int i = l - 1, j = r + 1;
        
        while (i < j) {
            while (q[++i] < x);
            while (q[--j] > x);
            if (i < j) {
                std::swap(q[i], q[j]);
            }
        }

        if (k <= j) 
            return helper(q, l, j, k);
        return helper(q, j + 1, r, k);
    }

};