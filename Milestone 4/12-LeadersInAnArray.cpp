//Leaders in an array

class Solution{
    public:
    vector<int> leaders(int a[], int n){
        vector <int> v;
        int temp = a[n-1];
        v.push_back(temp);
        for (int i = n-2; i >= 0; i --) 
            if (temp <= a[i]) {
                temp = a[i];
                v.push_back(temp);
            }
            
        reverse (v.begin(),v.end());
        return v;
    }
};
