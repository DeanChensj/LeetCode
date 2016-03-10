#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
 int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        
        int i = 0, j = 0, max_len = 1, tmp_len = 1;
        bool *hash = new bool[129];
        for (int i = 0; i < 129; i++) hash[i] = false;
        while (j < s.length()) {
            if (!hash[s[j]]) {
                hash[s[j]] = true;
                j++;
            } else {
                tmp_len = j - i;
                if (tmp_len > max_len) max_len = tmp_len;
                while (s[i++] != s[j]) {
                    hash[s[i-1]] = false;
                }
                j++;
            }
            
        }
        tmp_len = j - i;
        if (tmp_len > max_len) max_len = tmp_len;
        return max_len;
    }

int main(int argc, char const *argv[])
{
    string a = "ibaz";
	cout << lengthOfLongestSubstring(a) << endl;

    for (int i = 0; i < a.length(); i++){
        cout << (int) a[i] << " ";
    }
    cout << endl;
	return 0;
}
