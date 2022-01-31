//largest number in k swaps

class Solution
{
    public:
    void fun (string str,int n, int k, string &ans, int i) {
        if (!k) return;
        
        char maxno = str[i];
        for (int j = i+1; j < n; j ++)
            if (maxno < str[j]) maxno = str[j];
            
        if (maxno != str[i])    k --;
        
        for (int j = n-1; j >= i; j --)
            if (str[j] == maxno) {
                swap (str[j], str[i]);
                
                if (ans < str)  ans = str;
                
                fun (str, n, k, ans, i+1);
                swap (str[j], str[i]);
            }
    }
    
    string findMaximumNum(string str, int k)
    {
       string ans = str;
       fun (str, str.length(), k, ans, 0);
       return ans;
    }
};