//Column name from given column number

class Solution{
    public:
    string colName (long long int n)
    {
        string temp = " ";
        while (n) {
            n --;
            char c = 'A' + (n % 26);
            temp += c;
            n /= 26;
        }
        
        reverse (temp.begin(), temp.end());
        return temp;
    }
};
