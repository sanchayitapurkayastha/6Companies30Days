//split largest sum array

class Solution {
public:
    bool canSplit (vector <int> &nums, int sum, int m) {
        int count = 1, total = 0;
        for (int i = 0; i < nums.size(); i ++) {
            total += nums[i];
            if (total > sum) {
                total = nums[i];
                count ++;
            }
            if (count > m)  return false;
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int l = 0, r = 0;
        for (int i = 0; i < nums.size(); i ++) {
            l = max (l, nums[i]);
            r += nums[i];
        }
        while (l < r) {
            int mid = l + (r-l)/2;
            if (canSplit(nums, mid, m)) r = mid;
            else    l = mid + 1;
        }
        return l;
    }
};
