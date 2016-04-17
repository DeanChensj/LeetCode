#include "../Header.h"

using namespace std;
string multiply(string num1, string num2) {
    int len1 = num1.length(), len2 = num2.length();
    int *num = new int[len1 + len2];
    memset(num, 0, sizeof(int) * (len1 + len2));
    
    for (int i = len1-1; i >= 0; i--) {
        for (int j = len2-1; j >= 0; j--) {
            int t = (num1[i]-'0') * (num2[j]-'0');
            num[i+j+1] += t % 10;
            num[i+j] += t / 10;
        }
    }
    for (int i = len1+len2-1; i >=0; i--) {
        if (num[i] >= 10) {
            num[i-1] += num[i] / 10;
            num[i] %= 10;
        } 
    }
    string s = "";
    int i = 0;
    while (!num[i]) i++;
    for (; i < len1+len2; i++){
        s += num[i] + '0';
    }
    return s == "" ? "0" : s;
}

