class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>>& image, int row, int col,
             int color, int source) {
        if (sr >= 0 && sr < row && sc >= 0 && sc < col &&
            image[sr][sc] == source) {
            image[sr][sc] = color;
            dfs(sr + 1, sc, image, row, col, color, source);
            dfs(sr, sc + 1, image, row, col, color, source);
            dfs(sr - 1, sc, image, row, col, color, source);
            dfs(sr, sc - 1, image, row, col, color, source);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        int start = image[sr][sc];

        if (color == start)
            return image;

        dfs(sr, sc, image, n, m, color, start);
        return image;
    }
};