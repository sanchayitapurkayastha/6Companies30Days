//Burning tree

class Solution {
  public:
    Node *bfsParents (Node *root, map <Node*, Node*> &mp, int target) {
        Node *start;     
        queue <Node*> q;
        
        q.push(root);
        while (!q.empty()) {
            Node *temp = q.front();
            q.pop();
            
            if (temp->data == target)   start = temp;
            
            if (temp->left) {
                mp[temp->left] = temp;
                q.push(temp->left);
            }
            
            if (temp->right) {
                mp[temp->right] = temp;
                q.push(temp->right);
            }
        }
        
        return start;
    }
    
    int findTime (map <Node*, Node*> &mp, Node* target) {
        int time = 0;
        
        map <Node*, bool> vis;
        queue <Node*> q;
        
        q.push(target);
        vis[target] = 1;
        
        while (!q.empty()) {
            int qsize = q.size();
            bool fire = 0;
            
            while (qsize --) {
                Node *temp = q.front();
                q.pop();
                
                //left child
                if (temp->left && !vis[temp->left]) {
                    q.push(temp->left);
                    vis[temp->left] = 1;
                    fire = 1;
                }
                //right child
                if (temp->right && !vis[temp->right]) {
                    q.push(temp->right);
                    vis[temp->right] = 1;
                    fire = 1;
                }
                //parent
                if (mp[temp] && !vis[mp[temp]]) {
                    q.push(mp[temp]);
                    vis[mp[temp]] = 1;
                    fire = 1;
                }
            }
            
            if (fire)   time ++;
        }
        
        return time;
    }
    
    int minTime(Node* root, int target) 
    {
        map <Node*, Node*> mp;
        Node *start = bfsParents (root, mp, target);
        return findTime (mp, start);
    }
};
