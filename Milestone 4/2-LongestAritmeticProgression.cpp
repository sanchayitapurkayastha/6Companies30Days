//Find the length of the Longest Arithmetic Progression (LLAP) in it.

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        if (n <= 2) return n;
        
        vector <unordered_map <int, int>> dp(n);
        int maxlen = 2;
        for (int i = 0; i < n-1; i ++)
            for (int j = i + 1; j < n; j ++) {
                int d = A[j] - A[i];
                
                if (dp[i].find(d) != dp[i].end())
                    dp[j][d] = dp[i][d] + 1;
                
                else    dp[j][d] = 2;
                
                maxlen = max (maxlen, dp[j][d]);
            }
        
        return maxlen;
    }
};
