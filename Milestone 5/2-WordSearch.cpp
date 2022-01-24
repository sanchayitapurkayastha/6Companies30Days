//Word Search
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs (vector <vector <char>> &board, string &word, int i,int j, int src) {
        if (src == word.length())   return 1;
        
        int n = board.size(), m = board[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[src]) 
            return 0;
        
        char temp = board[i][j];
        board[i][j] = '#';
            
        int cx[] = {-1, 0, 1, 0}, cy[] = {0, -1, 0, 1};
        bool ans = 0;
        for (int k = 0; k < 4; k ++) {
            int x = i + cx[k], y = j + cy[k];
            if (x >= 0 && x < n && y >= 0 && y < m)
                ans = ans || dfs (board, word, x, y, src+1);
        }
        board[i][j] = temp;
        return ans;
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                if (dfs (board, word, i, j, 0))
                    return 1;
        
        return 0;
    }
};
