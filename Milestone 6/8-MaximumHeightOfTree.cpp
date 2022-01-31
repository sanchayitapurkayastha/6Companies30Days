//maximum height of tree

class Solution{
public:
    int height(int N){
        if (!N) return 0;
        
        int i = 1, h = 0;
        while (N && N >= i) {
            N -= i;
            i ++;
            h ++;
        }
        return h;
    }
};

/*-----------OR-----------*/
class Solution{
public:
    int height(int N){
        return (int)(-1 + sqrt(1 + 8 * N))/2;
    }
};