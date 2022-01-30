//power of numbers

class Solution{
    public:
    long long power(int N,int R)
    {
       if (!R)  return 1;
       
       int MOD = 1000000007;
       if (R == 1)  return N % MOD;
      
       long long temp = power (N, R/2) % MOD;
       temp = (temp * temp) % MOD;
       
       if (R & 1)   return (N * temp) % MOD;
       return temp % MOD;        
    }
};