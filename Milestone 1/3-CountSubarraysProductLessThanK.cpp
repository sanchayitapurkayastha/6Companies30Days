//Count the Number of Subarrays having Product less than K

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long prod = 1;
        int count = 0;
        for (int l = 0, r = 0; r < n; r ++) {
            prod *= a[r];
            
            while (l < r && prod >= k)  prod /= a[l++];
            
            if (prod < k)   count += 1 + r - l;
        }
        return count;
    }
};
