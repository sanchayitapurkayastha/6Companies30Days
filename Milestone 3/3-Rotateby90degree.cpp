//Rotate by 90 degree

void rotate(vector<vector<int> >& matrix)
{
    int n = matrix.size();
    //transpose of matrix
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < i; j ++)
            swap (matrix[i][j], matrix[j][i]);
    
    //reverse rows
    for (int i = 0; i < n/2; i ++) {
        int k = n-i-1;
        for (int j = 0; j < n; j ++)
            swap (matrix[i][j], matrix[k][j]);
    }
}