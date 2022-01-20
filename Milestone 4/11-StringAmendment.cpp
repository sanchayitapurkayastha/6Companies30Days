//string amendment

class Solution{
    public:
    string amendSentence (string s)
    {
        string ans = "";
        int n = s.length();
        for (int i = 0; i < n; i ++) {
            if (islower(s[i]))  ans += s[i];
            else if (i == 0 && isupper(s[i]))   ans += tolower(s[i]);
            else {
                ans += ' ';
                ans += tolower(s[i]);
            }
        }
        return ans;
    }
};
