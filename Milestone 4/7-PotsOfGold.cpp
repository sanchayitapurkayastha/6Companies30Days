//Pots of gold

class Solution {
public:
    int maxCoins(vector<int>&A,int n)
    {
	    int t[n][n];
	    memset (t, 0, sizeof(t));
	    for (int l = 1; l <= n; l ++)
	        for (int i = 0; i <= n-l; i ++) {
	            int j = i + l -1;
	            if (i == j) t[i][j] = A[i];
	            else if (i+1 == j)  t[i][j] = max(A[i], A[j]);
	            else {
	                int start = A[i] + min (t[i+2][j], t[i+1][j-1]);
	                int end = A[j] + min (t[i+1][j-1], t[i][j-2]);
	                t[i][j] = max (start, end);
	            }
	        }
	   
	    return t[0][n-1];
    }
};
