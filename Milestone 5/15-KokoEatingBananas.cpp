//koko eating bananas

class Solution {
public:
    bool check (vector <int>&arr, int n, int m, int h) {
        int time = 0;
        for (int i = 0; i < n; i ++) {
            if (arr[i] % m) time += (arr[i] / m) + 1;
            else    time += arr[i] / m;
        }
        if (time <= h)  return 1;
        else    return 0;
    } 
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = piles[0], n = piles.size();
        for (int i = 1; i < n; i ++)    end = max (end, piles[i]);
        while (start < end) {
            int mid = start + (end-start)/2;
            if (check (piles, n, mid, h))  end = mid;
            else    start = mid+1;
        }
        return end;
    }
};
