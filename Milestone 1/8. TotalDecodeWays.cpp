//Total decoding messages

class Solution {
	public:
	    int mod = 1000000007;
	    
		int CountWays(string str){
		    if (str[0] == '0')  return 0;
		    
		    int n = str.size();
		    int count [n+1];
		    memset (count, 0, sizeof (count));
		    count [0] = count [1] = 1;
		    
		    for (int i = 2; i <= n; i ++) {
		        if (str[i-1] > '0')
		            count[i] = (count[i] % mod + count[i-1] % mod) % mod;
		        
		        if (str[i-2] == '1' || (str[i-2] == '2' && str[i-1] < '7'))
		            count[i] = (count[i] % mod + count[i-2] % mod) % mod;
		    }
		    
		    return count[n] % mod;
		}

};
   