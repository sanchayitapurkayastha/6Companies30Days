//count number of subtrees having given sum

int subtreeSum (Node *root, int x, int &count) {
    if (!root)  return 0;
    
    int l = subtreeSum (root->left, x, count);
    int r = subtreeSum (root->right, x, count);
    int sum = root->data + l + r;
    
    if (sum == x)   count ++;
    return sum;
}

int countSubtreesWithSumX(Node* root, int X)
{
	int count = 0;
	subtreeSum (root, X, count);
	return count;
}
