//Nuts and Bolts problem

class Solution{
public:
    int partition (char arr[], int low, int high, char pivot) {
        int i = low-1;
        
        for (int j = low; j < high; j ++) {
            if (arr[j] < pivot) {
                i ++;
                swap (arr[i], arr[j]);
            }
            else if (arr[j] == pivot) {
                swap (arr[j], arr[high]);
                j --;
            }
        }
        swap (arr[i+1], arr[high]);
        return i+1;
    }
    
    void quicksort (char nuts[], char bolts[], int low, int high) {
        if (low < high) {
            int pi = partition (nuts, low, high, bolts[high]);
            partition (bolts, low, high, nuts[pi]);
            
            quicksort (nuts, bolts, low, pi-1);
            quicksort (nuts, bolts, pi+1, high);
        }
        return;
    }
    
	void matchPairs(char nuts[], char bolts[], int n) {
	    quicksort (nuts, bolts, 0, n-1);
	    return;
	}

};
