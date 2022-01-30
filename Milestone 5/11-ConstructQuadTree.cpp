//construct quad tree

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* fun (vector <vector <int>> &grid, int x1, int x2,int y1, int y2) {
        if (x1 == x2)
            return new Node (grid[x1][y1], true, NULL, NULL, NULL, NULL);
        
        int midx = x1 + (x2-x1)/2;
        int midy = y1 + (y2-y1)/2;
        
        Node *topLeft = fun (grid, x1, midx, y1, midy);
        Node *topRight = fun (grid, x1, midx, midy + 1, y2);
        Node *bottomLeft = fun (grid, midx + 1, x2, y1, midy);
        Node *bottomRight = fun (grid, midx + 1, x2, midy + 1, y2);
        
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf
           && bottomRight->isLeaf && topLeft->val == topRight->val
           && topRight->val == bottomLeft->val && 
            bottomLeft->val == bottomRight->val)
            return topLeft;
        
        return new Node (grid[x1][y1], false, topLeft, topRight, 
                         bottomLeft, bottomRight);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return !n? NULL: fun (grid, 0, n-1, 0, n-1);   
    }
};