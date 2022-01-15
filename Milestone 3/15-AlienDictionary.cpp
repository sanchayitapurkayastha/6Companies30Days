/*Find the order of characters in the alien language.*/

class Solution{
    public:
    void dfs (int src, vector<vector <int>> &chars, vector<bool> &vis, string &ans) {
        vis[src] = 1;
        
        for (auto i : chars[src])
            if (!vis[i])    dfs (i, chars, vis, ans);
        
        char ch = 'a' + src;
        ans = ch + ans;
    }
    
    string findOrder(string dict[], int N, int K) {
        vector <vector <int>> chars(K);
        for (int i = 0; i < N-1; i ++) {
            string w1 = dict[i], w2 = dict[i+1];
            int size = min (w1.length(), w2.length());
            
            for (int j = 0; j < size; j ++)
                if (w1[j] != w2[j]) {
                    chars[w1[j] - 'a'].push_back(w2[j] - 'a');
                    break;
                }
        }
        
        vector <bool> vis(K, 0);
        string ans = "";
        for (int i = 0; i < K; i ++)
            if (!vis[i])    dfs (i, chars, vis, ans);
        
        return ans;
    }
};
