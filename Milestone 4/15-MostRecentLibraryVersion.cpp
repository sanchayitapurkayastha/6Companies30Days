/*Given two library versions of an executable: 
for example, “10.1.1.3” and “10.1.1.9” or “10” and “10.1”. 
Find out which one is more recent? Strings can be empty also.*/

#include <bits/stdc++.h>
using namespace std;

int main () {
    string version1, version2;
    cin >> version1;
    cin >> version2;
    int n1 = version1.length(), n2 = version2.length();

    int i = 0, j = 0;
    while (i < n1 || j < n2) {
        int num1 = 0, num2 = 0;
        while (i < n1 && version1[i] != '.')    num1 = num1*10 + (version1[i++] - '0');
        while (j < n2 && version2[j] != '.')    num2 = num2*10 + (version2[j++] - '0');

        if (num1 > num2) {
            cout << version1 << "\n";
            break;
        }
        else if (num2 > num1) {
            cout << version2 << "\n";
            break;
        }
        i ++; j ++;
    }

    return 0;
}
