/*Divide an array into two sets S1 and S2 such that 
the absolute difference between their sums is minimum 
and find the minimum difference*/

class Solution{

  public:
    int minDifference(int arr[], int n)  { 
	    int S = 0;
	    for (int i = 0; i < n; i ++)   S += arr[i];
	    
	    int sum = S/2;
	    bool t [n+1][sum+1];
        
        for (int i = 0; i <= n; i ++)   t[i][0] = true;
        for (int i = 1; i <= sum; i ++) t[0][i] = false;
        
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= sum; j ++)
                if (arr[i-1] <= j) t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
                else    t[i][j] = t[i-1][j];
	    
	    int mn = INT_MAX;
	    for (int i = 0; i <= sum; i ++)    
	        if (t[n][i])
	            mn = min (mn, S - 2 * i);
	    return mn;
	} 
};
