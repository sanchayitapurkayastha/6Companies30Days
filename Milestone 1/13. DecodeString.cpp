//Decode the string

class Solution{
public:
    string fun (string &s, int &i) {
        string ans = "";
        int num = 0;
        
        for (; i < s.size(); i ++) 
            if (isdigit(s[i]))  num = num * 10 + (s[i]-'0');
        
            else if (s[i] == '[') {
                i ++;
                string temp = fun (s, i);
                while (num --)  ans += temp;
                num = 0;
            }
        
            else if (s[i] == ']')   return ans;
        
            else    ans += s[i];
        
        return ans;
    }
    
    string decodedString(string s){
        int i = 0;
        return fun (s, i);
    }
};
