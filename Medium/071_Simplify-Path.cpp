#include "../Header.h"

using namespace std;
string simplifyPath(string path) {
    if (path[path.length()-1] != '/') path = path + "/";
    stack<string> s;
    int bg = 1;
    for (int i = 1; i < path.length();i++) {
        if (path[i] == '/') {
            if (i-bg) {
                string q = path.substr(bg, i-bg);
                if (q == "."){}
                else if (q == "..") {
                    if (!s.empty()) s.pop();
                } else s.push(q);
            }
            bg = i+1;
        } 
    }
    if (s.empty()) return "/";
    string res = "";
    while (!s.empty()) {
        res = "/" + s.top() + res;
        s.pop();
    }
    return res;
}
int main(int argc, char const *argv[])
{
	return 0;
}
