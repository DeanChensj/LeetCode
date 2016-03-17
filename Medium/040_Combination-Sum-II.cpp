#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;
   void helper(vector<int> item, vector<vector<int> > &ans, vector<int> &candidates, int pos, int sum, int target) {
        int size = candidates.size();
        if (sum > target || (sum < target && pos > size)) return;
        if (sum == target) {
            ans.push_back(item);
            return;
        }
        for (int i = pos; i < size; i++) {
            // 当i == pos 时说明candidates[i-1]已经包含进了item中，此时candidates[i]可以重复利用
            if (i && candidates[i] == candidates[i-1] && (i > pos)) continue;
            int newSum = sum + candidates[i];
            
            if (newSum <= target) {
                item.push_back(candidates[i]);
                helper(item, ans, candidates, i+1, newSum, target);
                item.pop_back();
            }
        }   
    }

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        if (candidates.size() == 0) return ans;
        sort(candidates.begin(), candidates.end());
        
        vector<int> item;
        helper(item, ans, candidates, 0, 0, target);
        
        return ans;
    }
int main(int argc, char const *argv[])
{
    vector<int> num;
    num.push_back(10);
    num.push_back(1);
    num.push_back(2);
    num.push_back(7);
    num.push_back(6);
    num.push_back(1);
    num.push_back(5);
    vector<vector<int> > ans = combinationSum2(num, 8);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}
