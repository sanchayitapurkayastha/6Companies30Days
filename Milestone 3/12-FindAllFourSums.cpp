/*Find all the unique quadruple from the given array 
that sums up to the given number.*/

class Solution{
    public:
    
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
       vector <vector <int>> v;
        
        int n = arr.size();
        sort (arr.begin(), arr.end());
        
        for (int i = 0; i <= n-4; i ++)  {
            for (int j = i+1; j <= n-3; j ++) {
                int sum = k - arr[i] - arr[j];
                
                int l = j + 1, r = n - 1;
                while (l < r)
                    if (sum == arr[l] + arr[r]) {
                        v.push_back({arr[i], arr[j], arr[l], arr[r]});
                        
                        while (l < r && arr[l] == arr[l+1]) l ++;
                        while (l < r && arr[r] == arr[r-1]) r --;
                        
                        l ++; r --;
                    }
                    
                    else if (sum > arr[l] + arr[r])   l++;
                    else    r--;
                
                while (j < n-3 && arr[j] == arr[j+1])   j ++;
            }
            
            while (i < n-4 && arr[i] == arr[i+1])   i ++;
        }
        
        return v;
    }
};
