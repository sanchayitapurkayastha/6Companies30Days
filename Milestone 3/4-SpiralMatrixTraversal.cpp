//Spiral Traversing a matrix

class Solution
{   
    public: 
    vector<int> spirallyTraverse(vector<vector<int> > A, int r, int c) 
    {
        int top = 0, down = r-1;
        int left = 0, right = c-1;
        int dir = 0;
        vector <int> v;
        while (top <= down && left <= right) {
            switch (dir) {
                case 0: {
                    for (int i = left; i <= right; i ++)
                        v.push_back(A[top][i]);
                    top ++;
                }
                break;
                
                case 1: {
                    for (int i = top; i <= down; i ++)
                        v.push_back(A[i][right]);
                    right --;
                }
                break;
                
                case 2: {
                    for (int i = right; i >= left; i --)
                        v.push_back(A[down][i]);
                    down --;
                }
                break;
                
                case 3: {
                    for (int i = down; i >= top; i --)
                        v.push_back(A[i][left]);
                    left ++;
                }
                break;
            }
            
            dir = (dir+1) % 4;
        }
        return v;
    }
};
