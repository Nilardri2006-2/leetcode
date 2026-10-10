class Solution {
public:
    void bfs(int r, int c, vector<vector<int>>& vis,
             vector<vector<char>>& grid) {
        vis[r][c] = 1;
        queue<pair<int, int>> q;
        q.push({r, c});

        int n = grid.size();
        int m = grid[0].size();
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // // traverse for 8 directions, but in q, asked for 4 only
            // for (int delrow = -1; delrow <= 1; delrow++) {
            //     for (int delcol = -1; delcol <= 1; delcol++) {
            int delrow[] = {-1, 1, 0, 0};
            int delcol[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                // int nrow = row + delrow;
                // int ncol = col + delcol;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
 int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (!vis[row][col] && grid[row][col] == '1') {
                cnt++;
                bfs(row, col, vis, grid);
            }
        }
    }
    return cnt;
}
}
;