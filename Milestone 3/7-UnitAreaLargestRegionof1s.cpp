//unit area of largest region of 1's

class Solution
{
    public:
    bool isSafe (int i, int j, int n, int m, 
                vector <vector <int>> &grid, vector <vector <int>> &vis) {
        return i >= 0 && i < n && j >= 0 && j < m 
                && grid[i][j] && !vis[i][j];
    }
    
    void dfs (int i, int j, int n, int m, int &count,
              vector <vector <int>> &grid, vector <vector <int>> &vis) {
        vis[i][j] = 1;
        
        int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        for (int k = 0; k < 8; k ++)
            if (isSafe (i + row[k], j + col[k], n, m, grid, vis)) {
                count ++;
                dfs (i + row[k], j + col[k], n, m, count, grid, vis);
            }
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        int n =grid.size(), m = grid[0].size();
        vector<vector<int>> vis (n , vector<int> (m, 0));
        int count = 0;
        
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                if (grid[i][j] && !vis[i][j]) {
                    int temp = 1;
                    dfs (i, j, n, m, temp, grid, vis);
                    count = max (count, temp);
                }
                
        return count;
    }
};
