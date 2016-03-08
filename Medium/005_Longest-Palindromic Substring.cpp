#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    if (s == "" || s.size() == 1) return s;
    int min_start = 0, max_len = 1;
    for (int i = 0; i < s.size();) { // do not update i there.
        if (s.size() - i < max_len / 2) break;

        int j = i, k = i; // j moves left and k moves right
        while (k < s.size() - 1 && s[k] == s[k+1]) {
            k++;    // duplicate keys are always palindrome
        }
        i = k + 1; // jump to next middle point
        while (j > 0 && k < s.size() - 1 && s[j-1] == s[k+1]) {
            j--;
            k++;
        }
        int new_len = k - j + 1;
        if (new_len > max_len) {
            max_len = new_len;
            min_start = j;
        }

    }
    return s.substr(min_start, max_len);
}

int main(int argc, char const *argv[])
{
	cout << longestPalindrome("eabcb") << endl;
	return 0;
}
