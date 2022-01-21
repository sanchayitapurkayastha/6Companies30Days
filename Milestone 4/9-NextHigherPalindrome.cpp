/*Smallest palindromic number greater than N 
using the same set of digits as in N.*/

class Solution{
  public:
    void reverse(string &s, int i, int j) {
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    
    string nextPalin(string N) { 
        int n = N.length();
        if (n < 3)  return "-1";
        
        int mid = n/2 -1;
        int i, j;
        for (i = mid - 1; i >= 0; i --)
            if (N[i] < N[i+1])  break;
            
        if (i < 0)  return "-1";
        
        int smallest = i + 1;
        for (j = i + 2; j <= mid; j ++)
            if (N[j] > N[i] && N[j] <= N[smallest]) smallest = j;
        
        swap (N[i], N[smallest]);
        swap (N[n-1-i], N[n-1-smallest]);
        
        reverse (N, i+1, mid);
        if (n & 1)  reverse (N, mid+2, n-i-2);
        else    reverse (N, mid+1, n-i-2);
        
        return N;
    }
};
