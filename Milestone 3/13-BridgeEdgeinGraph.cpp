/*Given a Graph of V vertices and E edges and another edge(c - d), 
the task is to find if the given edge is a Bridge. i.e., 
removing the edge disconnects the graph.*/

class Solution
{
	public:
	void dfs (int src, vector <int> adj[], vector <bool> &vis, int c, int d) {
	    vis[src] = 1;
	    
	    for (auto i: adj[src]) {
	        if ((src == c && i == d) ||
	            (src == d && i == c))   continue;
	       
	        if (!vis[i])    dfs (i, adj, vis, c, d);
	    }    
	    return;
	}
	
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector <bool> vis(V, 0);
        
        dfs (c, adj, vis, c, d);
        
        if (!vis[d])    return 1;
        return 0;
    }
};