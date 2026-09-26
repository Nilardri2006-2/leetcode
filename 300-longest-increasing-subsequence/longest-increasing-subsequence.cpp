class Solution {
public:
    int f(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == nums.size())
            return 0;
        if (dp[ind][prev + 1] != -1)
            return dp[ind][prev + 1];
        // not take
        int len = 0;
        len = 0 + f(ind + 1, prev, nums, dp);
        // take
        if (prev == -1 || nums[ind] > nums[prev]) {

            len = max(len, 1 + f(ind + 1, ind, nums, dp));
        }
        return dp[ind][prev + 1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
                int len = 0 + dp[ind+1][prev_ind+1];
                // take
                if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {

                    len = max(len, 1 + dp[ind+1][ind+1]);
                }
                dp[ind][prev_ind + 1] = len;
            }
        }
        return dp[0][-1+1];
    }
};