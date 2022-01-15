/*.Given a destination D , find the minimum number of 
steps required to reach that destination.*/

class Solution{
public:
    int minSteps(int D){
        int sum = 0, count = 1;
        
        while (sum < D) {
            sum += count;
            count ++;
        }
        
        while (sum > D && ((sum - D) % 2)) {
            sum += count;
            count ++;
        }
        
        return --count;
    }
};
