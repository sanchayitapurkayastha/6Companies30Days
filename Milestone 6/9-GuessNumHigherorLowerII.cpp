//guess number higher or lower ii

class Solution {
public:
    int getMoneyAmount(int n) {
        int t[n+1][n+1];
        for (int len = 1; len <= n; len ++) 
            for (int start = 0; start <= n+1 - len; start ++) {
                int end = start + len -1;
                
                if (len == 1)   t[start][end] = 0;
               
                else if (len == 2)  t[start][end] = start;
                
                else {
                    int ans = INT_MAX;
                
                    for (int pivot = start+1; pivot < end; pivot ++) {
                        int temp = pivot + max (t[start][pivot-1], t[pivot+1][end]);
                        ans = min (ans, temp);
                    }
                    
                    t[start][end] = ans;
                }
            }
        
        return t[1][n];
    }
};