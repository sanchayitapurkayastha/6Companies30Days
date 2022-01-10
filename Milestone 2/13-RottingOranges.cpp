//Rotting Oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int fresh = 0;
        queue <pair <int, int>> q;
        for (int i = 0; i < m; i ++)
            for (int j = 0; j < n; j ++)
                if (grid[i][j] == 1)    fresh ++;
                else if (grid[i][j] == 2)   q.push({i,j});
        
        int cx[] = {-1, 0, 1, 0}, cy[] = {0, -1, 0, 1};
        int time = -1;
        while (!q.empty()) {
            int qsize = q.size();
            
            while (qsize --) {
                pair <int, int> temp = q.front();
                q.pop();
                //checking for neighboring 1s
                for (int i = 0; i < 4; i ++) {
                    int tx = temp.first + cx[i];
                    int ty = temp.second + cy[i];
                    
                    if (tx >= 0 && tx < m && ty >= 0 && ty < n
                       && grid[tx][ty] == 1) {
                        grid [tx][ty] = 2;
                        fresh --;
                        q.push({tx, ty});
                    }
                }  
            }
            
            time ++;
        }
        
        if (fresh)  return -1;
        else if (time == -1) return 0;
        else return time;
    }
};
