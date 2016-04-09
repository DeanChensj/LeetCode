#include "../Header.h"

using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string> > res;
    sort(strs.begin(), strs.end());
    
    int cnt = 0;
    //            hash_code   index
    unordered_map<string, int> hash;
    for (int i = 0; i < strs.size(); i++) {
        int *tmp = new int[26];
        memset(tmp, 0, 26*4);
        for (int j = 0; j < strs[i].length(); j++) tmp[strs[i][j] - 'a']++;
        
        string item = "";
        for (int i = 0; i < 26; i++) {
            item += (char)(tmp[i] & 0xff); 
            item += (char)((tmp[i] >> 8) & 0xff); 
            item += (char)((tmp[i] >> 16) & 0xff); 
            item += (char)((tmp[i] >> 24) & 0xff);
        }
        
        if (hash.find(item) == hash.end()) {
            hash[item] = cnt++;
            vector<string> item{strs[i]};
            res.push_back(item);
        } else res[ hash[item] ].push_back(strs[i]);
    }
    return res;
}

