#include "../Header.h"

using namespace std;
int calculate(string s) {
    stack<char> sign;
    stack<int> op;
    int l, r, num;
    for (int i = 0; i < s.length();) {
        if (s[i] == '*') sign.push('*'), i++;
        else if (s[i] == '/') sign.push('/'), i++;
        else if (s[i] == '+') sign.push('+'), i++;
        else if (s[i] == '-') sign.push('-'), i++;
        else if (s[i] == ' ') i++;
        else {
            num = 0;
            while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                num *= 10;
                num += s[i] - '0';
                i++;
            }
            if (!sign.empty()) {
                l = op.top();
                op.pop();
                switch (sign.top()) {
                    case '*':
                        sign.pop();
                        op.push(l * num);
                        break;
                    case '/' :
                        sign.pop();
                        op.push(l / num);
                        break;
                    default :
                        op.push(l);
                        op.push(num);
                }
            } else op.push(num);
        }
    }
    stack<int> op2;
    stack<int> sign2;
    while (!sign.empty()) {
        sign2.push(sign.top());
        sign.pop();
    }
    while (!op.empty()) {
        op2.push(op.top());
        op.pop();
    }
    while (!sign2.empty()) {
        l = op2.top();
        op2.pop();
        r = op2.top();
        op2.pop();
        if (sign2.top() == '+') op2.push(l + r);
        else op2.push(l - r);
        sign2.pop();
    }
    
    return op2.top();
}

int main(int argc, char const *argv[])
{
    string s = " 3+5 / 2 ";
    cout << s << " = " << calculate(s) << endl;
	return 0;
}
