//find in mountain array

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearch (MountainArray &arr, int t, int i, int j, bool asc) {
        while (i <= j) {
            int m = i + (j-i)/2;
            int curr = arr.get(m);
            if (curr == t)    return m;
            else if (asc == curr < t)  i = m+1;
            else    j = m-1;
        }
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();  
        int l = 0, r = n-1;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (mountainArr.get(mid) > mountainArr.get(mid+1))  r = mid;
            else    l = mid+1;
        }
        
        int ans = binarySearch (mountainArr, target, 0, l, true);
        if (ans == -1)  ans = binarySearch (mountainArr,target, l, n-1, false);
        return ans;
    }
};
