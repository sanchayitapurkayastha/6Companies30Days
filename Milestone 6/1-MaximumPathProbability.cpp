//path maximum probability

class Solution {
public:
    //double MOD = 1e-5;
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector <vector <pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i ++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        vector <bool> vis(n, 0);
        
        priority_queue <pair <double, int>> q;
        q.push({1.0, start});
        
        while (!q.empty()) {
            pair <double, int> top = q.top();
            q.pop();
            
            if (top.second == end) return top.first;
            
            if (!vis[top.second]) {
                vis[top.second] = 1;
                
                for (auto x: adj[top.second])
                    q.push({top.first * x.second, x.first});
            }
        }
        return 0; 
    }
};