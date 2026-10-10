class Solution {
public:
    void bfs(int r, int c, vector<vector<int>>& vis,
             vector<vector<int>>& grid) {
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
                    grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !vis[i][0])
                bfs(i, 0, vis, grid);

            if (grid[i][m - 1] == 1 && !vis[i][m - 1])
                bfs(i, m - 1, vis, grid);
        }

        // Traverse the first and last rows
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1 && !vis[0][j])
                bfs(0, j, vis, grid);

            if (grid[n - 1][j] == 1 && !vis[n - 1][j])
                bfs(n - 1, j, vis, grid);
        }

        // Count land cells that cannot reach the boundary
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j])
                    cnt++;
            }
        }

        return cnt;
    }
};