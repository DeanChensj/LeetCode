#include "../Header.h"

using namespace std;
vector<string> findRepeatedDnaSequences(string s) {
        int len = s.length(), tag = 0;
        vector<string> res;
        if (len < 10) return res;
        unordered_map<int, int> hash;
        for (int i = 0; i < 10; i++) {
            tag <<= 2;
            switch (s[i]) {
                case 'C':
                    tag += 1;
                    break;
                case 'G':
                    tag += 2;
                    break;
                case 'T':
                    tag += 3;
            }
        }
        hash[tag & 0xFFFFF] = 1; 
        for (int i = 10;  i < s.length(); i++) {
            tag <<= 2;
            switch (s[i]) {
                case 'C':
                    tag += 1;
                    break;
                case 'G':
                    tag += 2;
                    break;
                case 'T':
                    tag += 3;
            }
            tag &= 0xFFFFF;
            if (hash.find(tag) != hash.end() && hash[tag] == 1 ) {
                res.push_back(s.substr(i-9, 10));
            }
            hash[tag]++;
        }
        return res;
    }

int main(int argc, char const *argv[])
{
	vector<string> res;
    
    cout << findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT") << endl;
    for (auto i: res) cout << i << endl;
	return 0;
}
