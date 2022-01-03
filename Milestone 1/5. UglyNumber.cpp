//Find the Nth Ugly Number

#define ull unsigned long long

class Solution{
public:	
	ull getNthUglyNo(int n) {
	    if (n == 1) return 1;
	    
	    ull uglynos [n];
	    uglynos[0] = 1;
	    ull i2 = 0, i3 = 0, i5 = 0;
	    ull nm2 = 2, nm3 = 3, nm5 = 5;

	    for (ull i = 1; i < n; i ++) {
	        ull min_nm = min (nm2, min (nm3, nm5));
	        uglynos[i] = min_nm;
	        
	        if (min_nm == nm2)  {
	            i2 ++;
	            nm2 = uglynos[i2] * 2;
	        }
	        if (min_nm == nm3)  {
	            i3 ++;
	            nm3 = uglynos[i3] * 3;
	        }
	        if (min_nm == nm5) {
	            i5 ++;
	            nm5 = uglynos[i5] * 5;
	        }
	    }
	    return uglynos[n-1];
	}
};
