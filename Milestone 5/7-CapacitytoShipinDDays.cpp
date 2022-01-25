//capacity to ship packages within d days

class Solution {
public:
    bool check (vector <int> &arr, int n, int m, int days) {
        int count = 1, total = 0;
        for (int i = 0; i < n; i ++) {
            total += arr[i];
            if (total > m) {
                total = arr[i];
                count ++;
            }
            if (count > days)   return 0;
        }
        return 1;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0;
        int n = weights.size();
        for (int i = 0; i < n; i ++) {
            l = max (l, weights[i]);
            r += weights[i];
        }
        while (l < r) {
            int m = l + (r-l)/2;
            if (check (weights, n, m, days))    r = m;
            else    l = m+1;
        }
        return l;
    }
};
