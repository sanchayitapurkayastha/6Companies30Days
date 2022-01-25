//as far from land is possible

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue <pair <int, int>> q, q1;
        //pushing all land in the queue q;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                if (grid[i][j])
                    q.push({i,j});
       
        int steps = 0;
        while (!q.empty()) {
            steps ++;
            while (!q.empty()) {
                pair <int, int> temp = q.front();
                q.pop();
                
                int cx[] = {-1,0,1,0}, cy[] = {0,-1,0,1};
                for (int i = 0; i < 4; i ++) {
                    int x = temp.first + cx[i];
                    int y = temp.second + cy[i];
                    if (x >=0 && x < n && y >= 0 && y < m
                       && grid[x][y] == 0) {
                        q1.push({x, y});
                        grid[x][y] = 1;
                    }   
                }
            }
            
            swap (q, q1);
        }
        
        return steps == 1? -1 : steps-1;
    }
};
