#include <iostream>
#include <vector>
#include <string>
using namespace std;
   string addBinary(string a, string b) {
        int lenA(a.length()), lenB(b.length()), len(max(lenA, lenB));
        string res(len, ' ');
        int carry(0), pA(lenA-1), pB(lenB-1), p(len-1);
        while (pA >= 0 && pB >= 0) {
            int aa(a[pA--]-'0'), bb(b[pB--]-'0'), sum(aa+bb+carry);
            res[p--] = (sum & 1) + '0';
            carry = sum >> 1;
        }
        while (pA >= 0) {
            int aa(a[pA--]-'0'), sum(aa+carry);
            res[p--] = (sum & 1) + '0';
            carry = sum >> 1;
        }
        while (pB >= 0) {
            int bb(b[pB--]-'0'), sum(bb+carry);
            res[p--] = (sum & 1) + '0';
            carry = sum >> 1;
        }
        if (carry) res = '1' + res; 
        return res;
    }
int main(int argc, char const *argv[])
{

	cout << addBinary("11", "1") << endl;
	return 0;
}