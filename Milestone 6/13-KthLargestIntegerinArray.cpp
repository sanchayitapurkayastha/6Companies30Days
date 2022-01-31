//kth largest integer in array

class GreaterNumString {
    public:
        bool operator () (string &a, string &b) {
            if (a.size() != b.size())   return a.size() > b.size();
            return a > b;
        }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue <string, vector <string>, GreaterNumString> pq;
        for (string &x: nums) {
            pq.push(x);
            if (pq.size() > k)  pq.pop();
        }
        return pq.top();
    }
};