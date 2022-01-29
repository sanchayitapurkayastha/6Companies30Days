//course schedule II

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> indeg (numCourses, 0);
        vector <int> adj [numCourses];
        
        for (auto x: prerequisites) {
            adj[x[1]].push_back(x[0]);
            indeg[x[0]] ++;
        }
        
        queue <int> q;
        for (int i = 0; i < numCourses; i ++)
            if (!indeg[i])  q.push(i);
        
        int count = 0;
        vector <int> order;
        while (!q.empty()) {
            count ++;
            
            int temp = q.front();
            q.pop();
            order.push_back(temp);
            
            for (auto x: adj[temp]) {
                indeg[x] --;
                if (!indeg[x])  q.push(x);
            }
        }
        
        if (count != numCourses)    return vector <int> ();
        return order;
    }
};