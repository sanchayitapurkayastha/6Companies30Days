//find the missing number in the string

int getValue (const string &str, int i, int len) {
    if (i + len > str.length()) return -1;
    int n = 0;
    for (int j = 0; j < len; j ++) {
        int ch = str[i+j] - '0';
        
        if (ch < 0 ||ch > 9)    return -1;
        
        n = n*10 + ch;
    }
    return n;
}

int missingNumber(const string& str)
{
    for (int len = 1; len <=6; len ++) {
        int n = getValue (str, 0, len);
        if (n == -1)    break;
        
        int missno = -1;
        bool fail = 0;
        
        for (int i = len; str[i]; i += 1 + log10l(n)) {
            if ((missno == -1) && (getValue (str, i, 1+log10l(n+2)) == n+2)) {
                missno = n+1;
                n += 2;
            }
            else if (getValue (str, i, 1+log10l(n+1)) == n+1)   n ++;
            else {
                fail = 1;
                break;
            }
        }
        
        if (!fail)  return missno;
    }
    
    return -1;
}
