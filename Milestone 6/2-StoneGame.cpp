//stone game

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int t[n][n];
        for (int len = 1; len <= n; len ++) 
            for (int i = 0; i <= n-len; i ++) {
                int j = i + len - 1;
                if (i == j) t[i][j] = piles[i];
                else if (i+1 == j)  t[i][j] = max (piles[i], piles[j]);
                else {
                    int start = piles[i] + min (t[i+2][j], t[i+1][j-1]);
                    int end = piles[j] + min (t[i+1][j-1], t[i][j-2]);
                    t[i][j] = max (start, end);
                }
            }
        return t[0][n-1] > 0;
    }
};