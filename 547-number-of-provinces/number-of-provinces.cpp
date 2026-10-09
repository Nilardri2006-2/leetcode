class Solution {
public:
  // Convert adjacency matrix to adjacency list
  vector<vector<int>> adjmatrix_to_adjlist(int V, vector<vector<int>> &matrix) {

    vector<vector<int>> adj(V);

    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {

        // 1 means city i and city j are directly connected
        if (matrix[i][j] == 1) {
          adj[i].push_back(j);
        }
      }
    }

    return adj;
  }

  // Mark every city reachable from node as visited
  void dfs(int node, vector<int> &vis, vector<vector<int>> &adj) {
    vis[node] = 1;
    for (auto it : adj[node]) {
      // Visit only unvisited neighbors
      if (!vis[it]) {
        dfs(it, vis, adj);
      }
    }
  }

  int findCircleNum(vector<vector<int>> &isConnected) {
    int V = isConnected.size();
    vector<vector<int>> adj = adjmatrix_to_adjlist(V, isConnected);
    
    vector<int> vis(V, 0);
    
    int cnt = 0;

    for (int i = 0; i < V; i++) {
      // A new unvisited node means a new province
      if (vis[i] == 0) {
        // Visit the whole province of city i
        dfs(i, vis, adj);
        cnt++;
      }
    }
    return cnt;
  }
};