//Minimum Size Subarray Sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = 0;
        int min_size = INT_MAX;
        int sum = 0;
        
        while (end < n) {
            sum += nums[end];
            
            while (sum >= target) {
                min_size = min (min_size, end-start+1);
                sum -= nums[start];
                start ++;
            }
            
            end ++;
        }
        end --;
        
        while (sum >= target) {
                min_size = min (min_size, end-start+1);
                sum -= nums[start];
                start ++;
        }
        
        if (min_size == INT_MAX)    return 0;
        return min_size;
    }
};
