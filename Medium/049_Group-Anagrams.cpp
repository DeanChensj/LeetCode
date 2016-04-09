#include "../Header.h"

using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string> > res;
    sort(strs.begin(), strs.end());
    
    int cnt = 0;
    unordered_map<string, int> hash;
    for (int i = 0; i < strs.size(); i++) {
        int *tmp = new int[26];
        memset(tmp, 0, 26*4);
        for (int j = 0; j < strs[i].length(); j++) tmp[strs[i][j] - 'a']++;
        
        char *cs = new char[104]; 
        for (int i = 0; i < 26; i++) {
            cs[i*4] = tmp[i]; 
            cs[i*4+1] = tmp[i] >>= 4; 
            cs[i*4+2] = tmp[i] >>= 4; 
            cs[i*4+3] = tmp[i] >>= 4;
        }
        string item(cs, 104);
    
        if (hash.find(item) == hash.end()) {
            hash[item] = cnt++;
            vector<string> item{strs[i]};
            res.push_back(item);
        } else res[ hash[item] ].push_back(strs[i]);
    }
    return res;
}
