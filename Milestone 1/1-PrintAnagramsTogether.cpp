//Given an array of strings, return all groups of strings that are anagrams.

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        unordered_map <string, vector <string>> mp;        
        for (string x: string_list) {
            string temp = x;
            sort (temp.begin(),temp.end());
            mp [temp].push_back(x);
        }
        
        vector <vector <string>> ans;        
        for (auto &it: mp)  ans.push_back(it.second);
        
        return ans;
    }
};
