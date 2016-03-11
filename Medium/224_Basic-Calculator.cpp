#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int calculate(string s) {
        long result = 0, i = 0, flag = 1;
        stack<int> myStack;
        
        for (; i < s.length();) {
            switch (s[i]) {
                case ' ':
                    break;
                case '(':
                    myStack.push(result);
                    myStack.push(flag);
                    result = 0;
                    flag = 1;
                    break;
                case ')':
                    flag = myStack.top();
                    myStack.pop();
                    result *= flag;
                    result = myStack.top() + result;
                    myStack.pop();
                    break;
                case '+':
                    flag = 1;
                    break;
                case '-':
                    flag = -1;
                    break;
                default: {
                    long tmp = 0;
                    tmp += s[i] - '0';
                    while (i+1 < s.length() && s[i+1] >= '0' && s[i+1] <= '9') {
                        tmp *= 10;
                        tmp += s[++i] - '0';
                    }
                    result += tmp * flag;
                }
            }
            i++;
        }
        return result;
    }
int main(int argc, char const *argv[]){
	cout << calculate("1-(5)") << endl;
	return 0;
}
