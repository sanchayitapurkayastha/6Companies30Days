//Tree Serialization and Deserialization

class Solution
{
    public:
    void inorder (Node *root, vector <int> &v) {
        if (!root)  return;
        inorder (root->left, v);
        v.push_back(root->data);
        inorder (root->right, v);
        return;
    }
    
    vector<int> serialize(Node *root) 
    {
        vector <int> v;
        inorder (root, v);
        return v;
    }
    
    Node * deSerialize(vector<int> &A)
    {
       int n = A.size();
       struct Node *newRoot = new Node (-1);
       struct Node *temp = newRoot;
       for (int i = 0; i < n; i ++) {
           temp->right = new Node (A[i]);
           temp = temp->right;
       }
       return newRoot->right;
    }

};
