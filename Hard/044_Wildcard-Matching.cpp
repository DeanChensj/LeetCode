#include "../Header.h"

using namespace std;
bool isMatch(string s, string p) {
    int lenS = s.length(), lenP = p.length(), i;
    bool **match = new bool*[lenS+1];
    for (i = 0; i <= lenS; i++) match[i] = new bool[lenP+1];
    match[0][0] = 1;
    for (i = 1; i <= lenS; i++) match[i][0] = 0;
    for (i = 1; i <= lenP; i++) {
        match[0][i] = 1;
        if (p[i-1] != '*') {
            match[0][i] = 0;
            break;
        }
    }
    for (; i <= lenP; i++) match[0][i] = 0;
    
    for (i = 1; i <= lenS; i++) {
        for (int j = 1; j <= lenP; j++) {
            if (p[j-1] == '*') {
                match[i][j] = match[i][j-1] || match[i-1][j];
            } else {
                match[i][j] = p[j-1] == '?' ? match[i-1][j-1] : match[i-1][j-1] && (s[i-1] == p[j-1]); 
            }
        }
    }

    return match[lenS][lenP];
}

int main(int argc, char const *argv[])
{
    string s = "aa";
    string p = "?*";
	cout << "s = " << s << " p = " << p << endl;
    cout << "isMatch(s, p) = " << isMatch(s, p) << endl;
	return 0;
}
