//IPL 2021 - Match Day 2

class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        deque <int> d;
        vector <int> v;
        
        int i = 0;
        for (; i < k; i ++){
            while (!d.empty() && arr[i] >= arr[d.back()])   d.pop_back();
            
            d.push_back(i);
        }
        v.push_back( arr[d.front()] );
        
        for (; i < n; i ++) {
            while (!d.empty() && d.front() <= i-k)  d.pop_front();
            
            while (!d.empty() && arr[i] >= arr[d.back()])   d.pop_back();
            
            d.push_back(i);
            v.push_back( arr[d.front()] );
        }        
        return v;
    }
};
