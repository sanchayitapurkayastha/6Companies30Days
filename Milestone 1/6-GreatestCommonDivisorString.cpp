/* Given two strings str1 and str2. We say that str2 divides str1 if it's possible
to concatenate multiple str2 to get str1. For example, ab divides abab. if str2 does 
not divide str1, return -1. Otherwise, return the smallest string str3 such that str3 
divides both str1 and str2.*/

class Solution {
public:
    int gcd (int a, int b) {
        return (!b) ? a : gcd (b, a%b);
    }
    string gcdOfStrings(string str1, string str2) {
       return (str1 + str2 == str2 + str1) ? 
            str1.substr(0, gcd(str1.size(), str2.size())) : "";
    }
};
