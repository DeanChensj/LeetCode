#include "../Header.h"

using namespace std;
int evalRPN(vector<string>& tokens) {
    stack<int> nums;
    int l = 0, r = 0, res = 0;
    for (auto token: tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            r = nums.top();
            nums.pop();
            l = nums.top();
            nums.pop();
            if (token == "+") {res = l+r; nums.push(res);}
            else if (token == "-") {res = l-r; nums.push(res);}
            else if (token == "*") {res = l*r; nums.push(res);}
            else if (token == "/") { res = r == 0 ? 0 : l/r ; nums.push(res);}
        } else nums.push(atoi(token.c_str()));
    }
    return nums.top();
}

int main(int argc, char const *argv[])
{
	vector<string> tokens = genStrVector("3 13 +");
    
    cout << "Origin vec: " << toString(tokens) << endl;
    cout << "evalRPN = " << evalRPN(tokens) << endl;
	return 0;
}
