/*Given a pattern containing only I's and D's. I for increasing and D
for decreasing.Devise an algorithm to print the minimum number following
that pattern.*/

class Solution{   
public:
    string printMinNumberForPattern(string S){
        int n = S.size(), x = 1;
        string str = "";
        for (int i = 0; i < n; i ++) 
            if (S[i] == 'I')    str += to_string(x++);
            
            else {
                int countofD = 0;
                while (i < n && S[i] == 'D') {
                    i ++;
                    countofD ++;
                }
                countofD ++;
            
                for (int j = x+countofD-1; j >= x; j --)  str += to_string(j);
            
                x += countofD;
            }
        
        if (S[n-1] == 'I')  str += to_string(x);
        
        return str;
    }
};
