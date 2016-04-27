#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>
using namespace std;
 bool isNatural(string s) {
    if (s.empty()) return 0;
    for (int i = 0; i < s.length(); i++) if (s[i] > '9' || s[i] < '0') return 0;
    return 1;
}

bool isInteger(string s) {
    if (s.empty()) return 0;
    if (s[0] == '-' || s[0] == '+') return isNatural(s.substr(1, s.length()-1));
    return isNatural(s);
}

bool isDecimal(string s) {
    int i = 0; 
    for (; i < s.length(); i++) if (s[i] == '.') break;
    if (i == 0) return isNatural(s.substr(1, s.length()-1)); // ".10"
    if (!isInteger(s.substr(0, i))) return 0; 
    if (i == s.length() || i == s.length()-1) return 1; // "10.""
    return isNatural(s.substr(i+1, s.length()-i-1)); // "a.b"
}

string& trim(string &s) {
    if (s.empty()) return s;
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}

bool isNumber(string s) {
    trim(s);
    if (s.empty()) return 0;
    
    if (s[0] == '+' || s[0] == '-') s = s.substr(1, s.length()-1);
    int i;
    for (i = 0; i < s.length(); i++) if (s[i] == 'e') break;
    if (!i || !isDecimal(s.substr(0, i))) return 0; // " e10" or "NANe10"
    if (i == s.length()) return 1; // just a decimal 
    return isInteger(s.substr(i+1, s.length()-i-1));
}
int main(int argc, char const *argv[])
{
    cout << isNumber("2e10");
	return 0;
}
