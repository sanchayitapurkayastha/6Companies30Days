//Prerequisite Tasks

class Solution {
public:
    bool isCycle (int src, vector <vector <int>> &adj, vector <bool> &vis, vector <bool> &stack) {
        stack[src] = true;
        if (!vis[src]) {
            vis[src] = true;
            
            for (auto i : adj[src]) {
                if (!vis[i] && isCycle (i, adj, vis, stack))    return true;
                if (stack[i])   return true;
            }
        }
        
        stack[src] = false;
        return false;
    }
    
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    int P = pre.size();
	    vector <vector <int>> adj(N);
	    for (auto i : pre)  adj[i.first].push_back(i.second);
	    
	    vector <bool> vis(N, 0), stack(N, 0);
	    for (int i = 0; i < N; i ++)
	        if (!vis[i] && isCycle (i, adj, vis, stack))
	            return false;
	    
	    return true;
	}
};