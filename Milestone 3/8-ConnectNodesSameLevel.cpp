//connect nodes at same level

class Solution
{
    public:
    
    void connect(Node *root)
    {
       queue <Node *> q;
       q.push(root);
       
       while (!q.empty()) {
           Node *ans = NULL;
           int qsize = q.size();
          
           while (qsize --) {
               Node *temp = q.front();
               q.pop();
               
               if (temp->left)  q.push(temp->left);
               if (temp->right) q.push(temp->right);
               
               if (!ans)    ans = temp;
               else {
                   ans->nextRight = temp;
                   ans = ans->nextRight;
               }
           }
       }
    }    
      
};
