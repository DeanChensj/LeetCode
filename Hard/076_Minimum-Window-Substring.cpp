#include "../Header.h"

using namespace std;
string minWindow(string s, string t) {
    int *cnt = new int[128];
    memset(cnt, 0, 128 * 4);
  
    for (auto c : t) cnt[c]++;
    int bg = 0, ed= 0, head = 0, min = s.length() + 1, counter = t.length();
    while (ed < s.length()) {
        if (cnt[s[ed++]]-- > 0) counter--;
        while (!counter) {
            if (ed - bg < min) {
                min = ed - bg;
                head = bg;
            }
            if (cnt[s[bg++]]++ == 0) counter++;
        }
    }
    return min > s.length() ? "" : s.substr(head, min);
}

int main(int argc, char const *argv[])
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
	cout << "s = " << s << ", t = "<< t << ", minWindow = " minWindow(s, t) << endl;
	return 0;
}
