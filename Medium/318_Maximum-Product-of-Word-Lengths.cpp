#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
 
 int maxProduct(vector<string>& words) {
        int size = words.size(), maxPro = 0;
        vector<int> hash(size, 0);
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].length(); j++) {
                hash[i] |= 1 << (words[i][j] - 'a');
            }
            for (int j = 0; j < i; j++) {
                if (!(hash[i] & hash[j])) {
                    int tmp = words[i].length() * words[j].length();
                    maxPro = max(maxPro, tmp);
                }
            }
        }
        return maxPro;
    }
int main(int argc, char const *argv[])
{
    vector<string> num;
    num.push_back("abcw");
    num.push_back("baz");
    num.push_back("foo");
    num.push_back("bar");
    num.push_back("xtfn");
    num.push_back("abcdef");
    cout << maxProduct(num) << endl;
	return 0;
}
