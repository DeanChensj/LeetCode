#include <iostream>
#include <string>
#include <stack>
using namespace std;

int longestValidParentheses(string s) {
        int maxValid = 0;
        s += 'x';
        stack<int> Stack;
        for (int i = 0; i < s.length(); i++) {
            cout << maxValid << endl;
            if (s[i] == ')' && !Stack.empty() && s[Stack.top()] == '(') {
                Stack.pop();
            } else {
               if (Stack.empty()) {
                   maxValid = max(maxValid, i);
               } else {
                   maxValid = max(i - Stack.top() - 1, maxValid);
                   cout << s[Stack.top()] << endl;
               }
               Stack.push(i);
            }
        }
        return maxValid;
    }

int main(int argc, char const *argv[])
{
    string s = "(()";
	cout << longestValidParentheses(s) << endl;
	return 0;
}
