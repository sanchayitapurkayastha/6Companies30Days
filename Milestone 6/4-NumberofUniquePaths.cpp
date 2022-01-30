//number of unique paths

class Solution
{
    public:
    int NumberOfPath(int a, int b)
    {
        int t[a][b];
        for (int i = 0; i < a; i ++)
            for (int j = 0; j < b; j ++)
                if (!i || !j)   t[i][j] = 1;
                else    t[i][j] = t[i-1][j] + t[i][j-1];
        return t[a-1][b-1];
    }
};