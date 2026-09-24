class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, int n, int rn,
          vector<vector<vector<int>>>& dp) {
        if (ind == n || rn == 0)
            return 0;
        if (dp[ind][buy][rn] != -1)
            return dp[ind][buy][rn];
        int profit = 0;
        if (buy) {
            profit = max((-prices[ind] + f(ind + 1, 0, prices, n, rn, dp)),
                         f(ind + 1, 1, prices, n, rn, dp));
        } else {
            profit = max((prices[ind] + f(ind + 1, 1, prices, n, rn - 1, dp)),
                         f(ind + 1, 0, prices, n, rn, dp));
        }
        return dp[ind][buy][rn] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int remaining_transaction = 2;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return f(0, 1, prices, n, remaining_transaction ,dp);
    }
};