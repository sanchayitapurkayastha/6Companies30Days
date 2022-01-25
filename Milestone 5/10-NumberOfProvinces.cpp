//no of provinces

class Solution {
public:
    void dfs (vector<vector <int>> &arr, int n, int src, vector<bool> &vis) {
        vis[src] = 1;
        for (int j = 0; j < n; j ++)
            if (arr[src][j] && !vis[j])    dfs (arr, n, j, vis);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector <bool> vis (n, 0);
        for (int i = 0; i < n; i ++)
            if (!vis[i]) {
                count ++;
                dfs (isConnected, n, i, vis);
            }
        
        return count;
    }
};
