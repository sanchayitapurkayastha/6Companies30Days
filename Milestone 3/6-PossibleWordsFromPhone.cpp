//possible words from phone

class Solution
{
    public:
    string keypadChar (int i) {
        switch (i) {
            case 2: return "abc";
            case 3: return "def";
            case 4: return "ghi";
            case 5: return "jkl";
            case 6: return "mno";
            case 7: return "pqrs";
            case 8: return "tuv";
            case 9: return "wxyz";
        }
    }
    
    void fun (int i, int n, int a[], string s, vector<string> &ans) {
        if (i == n) {
            ans.push_back(s);
            return;
        }
        
        string keypad = keypadChar (a[i]);
        for (int j = 0; j < keypad.length(); j ++)
            fun (i + 1, n, a, s + keypad[j], ans);
    }
    
    vector<string> possibleWords(int a[], int N)
    {
        vector <string> ans;
        fun (0, N, a, "", ans);
        return ans;
    }
};
