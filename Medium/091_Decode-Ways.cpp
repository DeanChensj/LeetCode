#include "../Header.h"

using namespace std;
int numDecodings(string s) {
    int len = s.length(), *dp = new int[len+1];
    if (!len) return 0;
    memset(dp, 0, len*4);
    dp[0] = 1; dp[1] = 1;
    
    if (s[0] == '0') return 0;
    for (int i = 2; i <= len; i++) {
        bool a = (((s[i-2]-'0')*10+s[i-1]-'0' <= 26) && s[i-2] != '0');
        if (s[i-1] == '0') {
            if (s[i-2] == '2' || s[i-2] == '1') dp[i] = dp[i-2];
            else return 0;
        } else dp[i] = dp[i-1] + dp[i-2] * a;
    }
    
    return dp[len];
}
int main(int argc, char const *argv[])
{
    srand((int)time(NULL));
	string s = to_string(random(100000));
    
    cout << "s = " << s << ", numDecodings(s) = " << numDecodings(s) << endl;
	return 0;
} 
