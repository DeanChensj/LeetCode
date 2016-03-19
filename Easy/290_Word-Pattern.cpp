#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
  bool wordPattern(string pattern, string str) {
        unordered_map<char, string> hash;
        int bg(0), ed(0); 
        for(int i = 0; i < pattern.length(); i++) {
            if (bg >= str.length()) return false;
            while(str[ed] != ' ' && str[ed] != '\0') ed++;
            string item = str.substr(bg, ed-bg);
            bg = ed+1;
            ed = bg;
            
            if (hash.find(pattern[i]) == hash.end()) {
                hash[pattern[i]] = item;
            } else if (hash[pattern[i]] != item) {
                return false;
            }
        }
        if (bg < str.length()) return false;
        
        unordered_set<char> s1;
        unordered_set<string> s2;
        unordered_map<char, string>::iterator it;
        for (it = hash.begin(); it != hash.end(); it++) {
            s1.insert((*it).first);
            s2.insert((*it).second);
        }
        if (s1.size() != s2.size()) return false;
        
        return true;
    }


int main(int argc, char const *argv[])
{
	cout << wordPattern("aba", "aba") << endl;
	return 0;
}