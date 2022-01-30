//minimum swaps to arrange binary grid

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector <int> v(n);
        int swaps = 0;
        
        //first calculate the no of trailing zeroes in each row
        for (int i = 0; i < n; i ++) {
            int count = 0;
            for (int j = n-1; j >= 0; j --) {
                if (grid[i][j]) break;
                count ++;
            }
            v[i] = count;
        }
        
        //calculate swaps
        for (int i = 0; i < n; i ++) {
            bool flag = 0;
            int trailing_needed = n-1-i;
            
            for (int j = i; j < n; j ++)
                if (v[j] >= trailing_needed) {
                    flag = 1;
                    swaps += j-i;
                    v.insert(v.begin(), 1, v[j]);
                    v.erase(v.begin() + j+1);
                    break;
                }
                
            if (!flag)  return -1;
        }
        
        return swaps;
    }
};