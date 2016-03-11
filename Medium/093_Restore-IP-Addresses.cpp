#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;
    bool validate(string s) {
        switch (s.length()) 
        {
            case 3:
                if (atoi(s.c_str()) >= 256) return false;
            case 2:
                if (s[0] == '0') return false;
        }
        return 1;
    }

    void helper(string s, int index, string tmpStr, int cnt, vector<string> &res) {
        if (cnt == 4) {
            if (index == s.length()) {
                tmpStr.erase(tmpStr.end()-1);
                res.push_back(tmpStr);
            }
            return;
        }
        for (int offset = 1; offset < 3; offset++) {
            if (index + offset <= s.length()) {
                string subStr = s.substr(index, offset);
                if (validate(subStr)) {
                    string newTmp = tmpStr + subStr + ".";
                    helper(s, index + offset, newTmp, cnt + 1, res);
                }
            }
        }
        if (index + 3 <= s.length()) {
            string subStr = s.substr(index, 3);
            if (validate(subStr)) {
                string newTmp = tmpStr + subStr + ".";
                helper(s, index + 3, newTmp, cnt + 1, res);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.length() < 4 || s.length() > 12) return res;
        string tmpStr = "";
        helper(s, 0, tmpStr, 0, res);
        return res;
    }

int main(int argc, char const *argv[])
{
    string a = "010010";
    vector<string> res = restoreIpAddresses(a);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
	return 0;
}
