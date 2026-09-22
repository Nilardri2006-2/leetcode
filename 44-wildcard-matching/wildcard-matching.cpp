class Solution {
public:
    bool f(int i, int j, string& p, string& s , vector<vector<int>>&dp) {
        if (i == 0 && j == 0)
            return true;
        if (i == 0 && j > 0)
            return false;
        if (i > 0 && j == 0) {
            for (int ii = 1; ii <= i; ii++)
                if (p[ii-1] != '*')
                    return false;
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if (p[i-1] == s[j-1] || p[i-1] == '?')
            return dp[i][j]= f(i - 1, j - 1, p, s ,dp);
        if (p[i-1] == '*')
            return dp[i][j]= f(i - 1, j, p, s , dp) | f(i, j - 1, p, s , dp);

        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n , m , p, s , dp);
    }
};