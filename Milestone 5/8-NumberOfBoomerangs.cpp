//no of boomerangs

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map <long long, int> mp;
        int count = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i == j) continue;
                long long d = pow(points[i][0]-points[j][0], 2) + pow(points[i][1]-points[j][1], 2);
                count += 2 * mp[d];
                mp[d] ++;
            }
            mp.clear();
        }
        return count;
    }
};
