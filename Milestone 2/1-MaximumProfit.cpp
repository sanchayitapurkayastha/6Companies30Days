//Calculating Maximum Profit

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        int t[K+1][N];
        for (int i = 0; i <= K; i ++) {
            int prevDiff = INT_MIN;
            for (int j = 0; j < N; j ++) {
                if (!i || !j)   t[i][j] = 0;
                else {
                    prevDiff = max (prevDiff, t[i-1][j-1] - A[j-1]);
                    t[i][j] = max (t[i][j-1], prevDiff + A[j]);
                }
            }
        }
        return t[K][N-1];
    }
};
