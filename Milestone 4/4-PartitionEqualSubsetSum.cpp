//Partition Equal Subset sum

class Solution{
public:
    int subsetSum (int n, int arr[], int sum) {
        int t[sum + 1];
        memset (t, 0, sizeof(t));
        t[0] = 1;
        for (int i = 0; i < n; i ++)
            for (int j = sum; j >= arr[i]; j --)
                if (t[j - arr[i]])  t[j] = 1;
                
        return t[sum];
    }
    
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i ++)    sum += arr[i];
        
        if (sum & 1)    return 0;
        return subsetSum (N, arr, sum/2);
    }
};
