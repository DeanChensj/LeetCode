#include "../Header.h"

using namespace std;
int myAtoi(string str) {
    int i = 0, sign = 1;
    long long num = 0, prevNum = 0;
    while (i < str.length() && str[i] == ' ') i++;
    if (i == str.length()) return 0;
    
    if (str[i] == '+') i++;
    else if (str[i] == '-') {
        i++;
        sign = -1;
    }
    if (str[i] < '0' || str[i] > '9') return 0;
    else num = (str[i++] - '0') * sign; 
    
    for (; i < str.length(); i++) {
        if (str[i] < '0' || str[i] > '9') return num;
        prevNum = num;
        num = num * 10 + (str[i] - '0') * sign;
        if (num > INT_MAX) {
            return INT_MAX;
        } else if (num < INT_MIN) {
            return INT_MIN;            
        }
    }
    
    return num; 
}
int main(int argc, char const *argv[])
{
	return 0;
}