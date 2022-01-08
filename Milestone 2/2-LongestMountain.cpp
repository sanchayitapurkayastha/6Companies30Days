//Longest Mountain Array

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3)  return 0;
        
        int len = 0, up = 0, down = 0;
        for (int i = 1; i < n; i ++) {
            if (down && arr[i-1] < arr[i] || arr[i-1] == arr[i])
                up = down = 0;
            up += arr[i-1]  <arr[i];
            down += arr[i-1] > arr[i];
            if (up && down) len = max (len, up + down + 1);
        }
        return len;
    }
};
