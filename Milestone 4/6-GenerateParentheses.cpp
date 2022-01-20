//Generate all combinations of well-formed(balanced) parentheses.

class Solution
{
    public:
    void fun (int open, int close, string s, vector <string> &v) {
        if (!open && !close) {
            v.push_back(s);
            return;
        }
        if (open > close)   return;
        if (open) {
            string s1 = s;
            s1 += '(';
            fun (open-1, close, s1, v);
        }
        if (close >= open) {
            string s2 = s;
            s2 += ')';
            fun (open, close-1, s2, v);
        }
        return;
    }
    
    vector<string> AllParenthesis(int n) 
    {
        vector <string> v;
        fun (n, n, "", v);
        return v;
    }
};
