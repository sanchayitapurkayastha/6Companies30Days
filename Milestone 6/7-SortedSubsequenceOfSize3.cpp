//sorted subsequence of size3

class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        vector <int> v;
        
        if (N < 3)  return v;
        
        int prev = arr[0], curr  = -1, next = -1;
        for (int i = 0; i < N; i ++) {
            if (curr != -1 && next != -1)   break;
            
            if (arr[i] < prev && curr == -1)    prev = arr[i];
            else if (arr[i] > prev && (curr == -1 || arr[i] < curr))  curr = arr[i];
            else if (arr[i] > curr && curr != -1 && next == -1)    next = arr[i];
        }
        
        if (curr != -1 && next != -1) {
            v.push_back(prev);
            v.push_back(curr);
            v.push_back(next);
        }
        return v;
    }
};