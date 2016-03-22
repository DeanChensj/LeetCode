#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return n;
        int ans = 0, *curLen = new int [n];
        for (int i = 0; i < n; i++) {
            int maxLen = 1, tmpLen = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]){
                    tmpLen = curLen[j] + 1;
                    if (tmpLen > maxLen) maxLen = tmpLen;
                }
            }
            curLen[i] = maxLen;
            if (maxLen > ans) ans = maxLen;
        }
        return ans;
    }

int main(int argc, char const *argv[])
{
	vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(31);
    num.push_back(0);
    cout << lengthOfLIS(num) << endl;
	return 0;
}
