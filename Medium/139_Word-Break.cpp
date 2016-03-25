#include "../Header.h"

using namespace std;
bool wordBreak(string s, unordered_set<string>& wordDict) {
    vector<bool> res(s.size()+1, 0);
    res[0] = 1;
    int maxLen = 0;
    for (auto word: wordDict) {
        if (word.length() > maxLen) maxLen = word.length();
    }
    
    for (int ed = 1; ed <= s.size(); ed++) {
        for (int bg = max(0, ed-maxLen); bg <= ed; bg++) {
            if (res[bg]) {
                if (wordDict.find(s.substr(bg, ed-bg)) != wordDict.end()) {
                    res[ed] = 1;
                    break;
                }
            }
            
        }
    }
   return res[s.size()];
}
int main(int argc, char const *argv[])
{
	unordered_set<string> wordDict;
    wordDict.insert("leet");
    wordDict.insert("code");
    cout << wordBreak("leetcode", wordDict) << endl;
	return 0;
}
