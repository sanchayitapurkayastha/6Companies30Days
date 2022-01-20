//implement Atoi

class Solution{
  public:
    long long atoi(string str) {
        long long no = 0;
        int i = 0;
        if (str[i] == '-')  i ++;
        for (; str[i]; i ++) {
            if (str[i] >='0' && str[i] <= '9') {
                int temp = str[i] - '0';
                no = no*10 + temp;
            }
            else    return -1;
        }
        if (str[0] == '-')  no *= -1;
        return no;
    }
};
