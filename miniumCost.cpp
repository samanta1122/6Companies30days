#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        auto nth = nums.begin() + n / 2;
        nth_element(nums.begin(), nth, nums.end());
        int median = *nth;

        auto m = [n](int idx) { return (2 * idx + 1) % (n | 1); };
        int first = 0, mid = 0, last = n - 1;

        while (mid <= last) {
            if (nums[m(mid)] > median) {
                swap(nums[m(first)], nums[m(mid)]);
                ++first;
                ++mid;
            } else if (nums[m(mid)] < median) {
                swap(nums[m(mid)], nums[m(last)]);
                --last;
            } else {
                ++mid;
            }
        }
    }
};


class Solution {
public:

    int D[26][26];
    void FW(vector<char>& original, vector<char>& changed, vector<int>& cost) {
        fill(&D[0][0], &D[0][0] + 26 * 26, INT_MAX); // Use C++ fill
        const int sz = original.size();
        for (int i = 0; i < sz; i++) {
            int row = original[i] - 'a';
            int col = changed[i] - 'a';
            D[row][col] = min(D[row][col], cost[i]);
        }
        for (int i = 0; i < 26; i++)
            D[i][i] = 0;

        for (int k = 0; k < 26; k++)
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    D[i][j] =
                        min((long long)D[i][j], (long long)D[i][k] + D[k][j]);
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        FW(original, changed, cost);
        const int n = source.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int row = source[i] - 'a';
            int col = target[i] - 'a';
            if (D[row][col] == INT_MAX)
                return -1;
            ans += D[row][col];
        }
        return ans;
    }
};