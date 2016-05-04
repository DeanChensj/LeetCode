#include "../Header.h"

using namespace std;
string reverseVowels(string s) {
    unordered_set<char> vows({'a','e','i','o','u','A','E','I','O','U'});
    int i = 0, j = s.length();
    while (i < j) {
        if (vows.find(s[i]) != vows.end()) {
            while (i < j && vows.find(s[j]) == vows.end()) j--;
            swap(s[i], s[j]);
            j--;
        }
        i++;
    }
    return s;
}
int main(int argc, char const *argv[])
{
	return 0;
}