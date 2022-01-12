//Stock Span Problem

class Solution
{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
       stack <pair <int, int>> s;
       vector <int> v (n);
       
       int count = 1, i = 0;
       while (i < n) {
            if (s.empty() || s.top().first > price[i]) {
                s.push({price[i], count});
                v[i] = count;
                count = 1; 
                i ++;
            }
            
            else {
                count += s.top().second;
                s.pop();
            }
       }
        
        return v;
    }
};
