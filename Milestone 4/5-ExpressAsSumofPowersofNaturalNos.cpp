/*Total number of ways n can be expressed as sum of 
xth power of unique natural numbers*/

class Solution{
    public:
    long long numOfWays(int n, int x)
    {
        long long t[n + 1];
        memset (t, 0, sizeof(t));
        t[0] = t[1] = 1;
        int limit = pow (n, 1.0/x);
        
        for (int i = 2; i <= limit; i ++) {
            long long currpow = pow (i, x);
            for (int j = n; j >= currpow; j --)
                t[j] += t[j-currpow] % 1000000007;
        }
        
        return t[n] % 1000000007;
    }
};
