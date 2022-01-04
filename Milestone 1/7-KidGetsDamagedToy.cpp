//Find the position of M-th item

class Solution {
  public:
    int findPosition(int N , int M , int K) {
        if (M <= N - K + 1) return M + K - 1;
        
        M -= N - K + 1;
        if (M % N)  return M % N;
        return N;
    }
};
