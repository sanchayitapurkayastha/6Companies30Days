//Find a continuous sub-array which adds to a given number S.

class Solution
{
    public:
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int l, r, sum;
        l = r = sum = 0;
        while (l < n & r <= n) {
            if (sum < s){
                sum += arr[r];
                r ++;
            }   
            else if (sum > s) {
                sum -= arr[l];
                l ++;
            }
            else return {l+1, r};
        }
        
        return {-1};
    }
};
