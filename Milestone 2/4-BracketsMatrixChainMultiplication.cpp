//Brackets in matrix chain multiplication

class Solution{
public:
    string str = "";
    
    void outputStr (int i, int j, int n, int *brackets, char &ch) {
        if (i > j)  return;
        
        if (i == j) {
            str += ch;
            ch ++;
            return;
        }
        
        str += '(';
        
        outputStr (i, *((brackets + i * n) + j), n, brackets, ch);
        outputStr (*((brackets + i * n) + j) + 1, j, n, brackets, ch);
        
        str += ')';
        return;
    }
    
    string matrixChainOrder(int p[], int n){
        int m [n][n];
        int brackets [n][n];
        
        for (int i = 1; i < n; i ++)    m[i][i] = 0;
        
        for (int L = 2; L < n; L ++)
            for (int i = 1; i < n-L+1; i ++) {
                int j = i + L - 1;
                m[i][j] = INT_MAX;
                
                for (int k = i; k < j; k ++) {
                    int count = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                    if (count < m[i][j]) {
                        m[i][j] = count;
                        brackets[i][j] = k;
                    }
                }
            }
        
        char ch = 'A';
        outputStr (1, n-1, n, (int*) brackets, ch);
        return str;
    }
};
