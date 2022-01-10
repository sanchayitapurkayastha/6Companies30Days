//Which among them forms a perfect Sudoku Pattern ?

class Solution{
public:
    int isValid(vector<vector<int>> mat) {
        set <string> hashset;
        for (int i = 0; i < 9; i ++)
            for (int j = 0; j < 9; j ++)
                if (mat[i][j])
                    if(!hashset.insert("row" + to_string(i) + to_string(mat[i][j])).second ||
                        !hashset.insert("col" + to_string(j) + to_string(mat[i][j])).second ||
                        !hashset.insert("box" + to_string((i/3)*3+(j/3)) + to_string(mat[i][j])).second)
                        return 0;
        return 1;
    }
};