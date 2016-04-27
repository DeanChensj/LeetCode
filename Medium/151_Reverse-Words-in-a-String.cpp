#include "../Header.h"

using namespace std;
void reverseWords(string &s) {
    string t = "";
    int len = s.length();
    for(int i = 0; i < len;) {
        while (s[i] == ' ') i++;
        if (i == len) break;
        int j = i;
        for (; j < len; j++) if (s[j] == ' ') break;
        if (s[j] == ' ') t = s.substr(i, j-i) + " " + t;
        else t = s.substr(i, j-i+1) + " " + t;
        i = j+1;
    }
    s = t.substr(0, t.length()-1);
}
int main(int argc, char const *argv[])
{
    string s = " I AM your   father ";
    cout << s << endl;
    reverseWords(s);
    cout << s << endl;
	return 0;
}
