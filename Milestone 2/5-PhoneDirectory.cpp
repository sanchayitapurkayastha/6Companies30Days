//Phone Directory

class Solution{
public:
    vector <string> fun (int n, string contact[], string s) {
        int slen = s.length();
        vector <string> v;
        map <string, int> mp;
        
        for (int i = 0; i < n; i ++)
            if (contact[i].length() >= slen && s == contact[i].substr(0, slen))
                mp[contact[i]] ++;
        
        for (auto m : mp)   v.push_back(m.first);
        if (!v.size())  v.push_back("0");
        return v;
    }
    
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        sort (contact, contact+n);
        vector <vector <string>> v;
        
        int slen = s.length();
        for (int i = 1; i <= slen; i ++) {
            vector <string> temp = fun (n, contact, s.substr(0, i)); 
            v.push_back(temp);
        }
        return v;
    }
};
