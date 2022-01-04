/*Given an unsorted array Arr of size N of positive integers. One number 
'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in 
array. Find these two numbers.*/

class Solution{
public:
    int a[2];
    int *findTwoElement(int *arr, int n) {
        // code here
        //repeating element
        for (int i = 0; i < n; i ++) 
            if (arr[abs(arr[i])-1] > 0)
                arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
            else    a[0] = abs(arr[i]);
                
        
        //missing element
        for (int i = 0; i < n; i ++)
            if (arr[i] > 0) {
                a[1] = i+1;
                break;
            }
            
        return a;
    }
};
