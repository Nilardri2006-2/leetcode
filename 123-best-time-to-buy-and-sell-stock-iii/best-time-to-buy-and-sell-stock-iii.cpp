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
        int rn = 2;
        // vector<vector<vector<int>>> dp(
        //     n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        // return f(0, 1, prices, n, remaining_transaction ,dp);
        vector<vector<int>> next(2, vector<int>(3, 0));

        next[0][0] = next[0][1] = next[0][2] = 0;
        
        for (int ind = n - 1; ind >= 0; ind--) {
        vector<vector<int>> curr(2, vector<int>(3, 0));
            for (int buy = 0; buy <= 1; buy++) {
                for (int rn = 1; rn <= 2; rn++) {
                    int profit = 0;
                    if (buy) {
                        profit = max(
                            (-prices[ind] + next[0][rn]),
                            next[1][rn]);
                    } else {
                        profit = max((prices[ind] +
                                      next[1][rn-1]),
                                     next[0][rn]);
                    }
                    curr[buy][rn] = profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }
};