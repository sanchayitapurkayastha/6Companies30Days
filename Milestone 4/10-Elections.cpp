//Winner of an election

class Solution{
  public:
  
    vector<string> winner(string arr[],int n)
    {
        map <string, int> mp;
        int maxvote = 0;
        for (int i = 0; i < n; i ++) {
            mp[arr[i]] ++;
            maxvote = max (maxvote, mp[arr[i]]);
        }
        string s = "";
        for (auto i : mp) 
            if (i.second == maxvote && (s.empty() || i.first < s))
                s = i.first;
        
        return {s, to_string(maxvote)};
    }
};
