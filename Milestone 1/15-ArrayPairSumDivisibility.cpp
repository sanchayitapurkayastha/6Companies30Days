//Array Pair Sum Divisibility Problem

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();
        if (n & 1)    return false;
        
        unordered_map <int, int> mp;
        for (int i : nums)  mp [(i%k + k) %k] ++;
        
        if (mp[0] & 1)  return false;
        
        for (int i = 1; i < k; i ++)    if (mp[i] != mp[k-i])   return false;
        
        return true;
    }
};
