//Stickler Thief

class Solution
{
    public:
    int FindMaxSum(int arr[], int n)
    {
        if (!n) return 0;
	    if (n == 1) return arr[0];
	    if (n == 2) return max (arr[0], arr[1]);
	    
	    int val1 = arr[0], val2 = max (arr[0], arr[1]);
	    int val;
	    for (int i = 2; i < n; i ++) {
	        val = max (val2, val1 + arr[i]);
	        val1 = val2;
	        val2 = val;
	    }
	    return val;
    }
};
