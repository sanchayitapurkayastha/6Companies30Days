//pacific atlantic water flow

class Solution {
public:
    void dfs (vector <vector <int>> &heights, int i, int j, int prev, 
              vector <vector <bool>> &ocean) {
        int m = heights.size(), n = heights[0].size();
        
        if (i < 0 || i >= m || j < 0 || j >= n ||
            heights[i][j] < prev || ocean[i][j]) return;
        
        ocean[i][j] = true;
        int cx[] = {-1,0,1,0}, cy[] = {0,-1,0,1};
        for (int k = 0; k < 4; k ++)
            dfs (heights, i+cx[k], j+cy[k], heights[i][j], ocean);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        
        vector <vector <bool>> pacific(m, vector <bool> (n,false));
        vector <vector <bool>> atlantic(m, vector <bool> (n,false));
        
        for (int i = 0; i < m; i ++) 
            for (int j = 0; j < n; j ++) {
                if (!i || !j)   
                    dfs (heights, i, j, INT_MIN, pacific);
                if (i == m-1 || j == n-1)
                    dfs (heights, i, j, INT_MIN, atlantic);
            }
        
        vector <vector <int>> ans;
        for (int i = 0; i < m; i ++)
            for (int j = 0; j < n; j ++)
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
        return ans;
    }
};