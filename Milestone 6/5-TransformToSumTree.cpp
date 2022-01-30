//transform to sum tree

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:

    int fun (Node *root) {
        if (!root)  return 0;
        
        int l = fun (root->left);
        int r = fun (root->right);
        int temp = root->data;
        
        root->data = l + r;
        
        return temp + root->data;
    }
    
    void toSumTree(Node *node)
    {
        fun (node);
    }
};