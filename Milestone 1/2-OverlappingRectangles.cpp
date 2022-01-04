//Overlapping Rectangles

class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        //if one rectangle is on the left side of another
        if (L1[0] > R2[0] || L2[0] > R1[0]) return 0;
        //if one rectangle is on top of another
        if (L1[1] < R2[1] || L2[1] < R1[1]) return 0;
        //rectangles overalp
        return 1; 
    }
};
